#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include "dds/dds.hpp"

#include "cc/sub.hpp"
#include "cc/pub.hpp"

class CcUnitTests : public ::testing::Test {
protected:

    /// @brief The thread that runs the subscriber implementation.
    void SetUp() override {

    }

    void MockPub() {
        dds::domain::DomainParticipant participant(org::eclipse::cyclonedds::domain::default_id());
        dds::topic::Topic<HelloWorldData::Msg> topic(participant, "HelloWorldData_Msg_cc");
        dds::pub::Publisher publisher(participant);
        dds::pub::DataWriter<HelloWorldData::Msg> writer(publisher, topic);

        std::cout << "=== [Publisher] Waiting for subscriber." << std::endl;
        while (writer.publication_matched_status().current_count() == 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
        std::cout << "=== [Publisher] Write sample: " << std::endl;
        /* Create a message to write. */
        HelloWorldData::Msg msg(1, "Hello World");
        writer.write(msg);
        std::cout << "=== [Publisher] Waiting for sample to be accepted." << std::endl;
        while (writer.publication_matched_status().current_count() > 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        return;
    }

    void MockSub() {
        dds::domain::DomainParticipant participant(org::eclipse::cyclonedds::domain::default_id());
        dds::topic::Topic<HelloWorldData::Msg> topic(participant, "HelloWorldData_Msg_cc");
        dds::sub::Subscriber subscriber(participant);
        dds::sub::DataReader<HelloWorldData::Msg> reader(subscriber, topic);   

        while (true) {
            dds::sub::LoanedSamples<HelloWorldData::Msg> samples;
            samples = reader.take();
            if (samples.length() > 0) {
                dds::sub::LoanedSamples<HelloWorldData::Msg>::const_iterator sample_iter;
                for (sample_iter = samples.begin(); sample_iter < samples.end(); ++sample_iter) {
                    const dds::sub::SampleInfo& info = sample_iter->info();
                    if (info.valid()) {
                        return;
                    }
                }
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
            }
        }
    }

    void TearDown() override {
    }

    std::thread sub_thread;
    std::thread pub_thread;

};



TEST_F(CcUnitTests, CcSubUnitTests) {
    ::testing::internal::CaptureStdout();

    sub_thread = std::thread([this]{
        sub_impl("HelloWorldData_Msg_cc");
    });
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    MockPub();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    sub_thread.join();

    std::string output = ::testing::internal::GetCapturedStdout();
    std::cout << output << std::endl;
    std::string expected_output = "=== [Subscriber] Message received: [userID: 1, message: Hello World]";
    ASSERT_THAT(output, ::testing::HasSubstr(expected_output));
}

TEST_F(CcUnitTests, CcPubUnitTests) {
    ::testing::internal::CaptureStdout();

    pub_thread = std::thread([this]{
        pub_impl("HelloWorldData_Msg_cc");
    });
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    MockSub();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    pub_thread.join();

    std::string output = ::testing::internal::GetCapturedStdout();
    std::cout << output << std::endl;
    std::string expected_output = "=== [Publisher] Write sample: [userID: 1, message: Hello World]";
    ASSERT_THAT(output, ::testing::HasSubstr(expected_output));
}
