set(source_files
    helper/wimax-helper.cc
    model/cid.cc
    model/cid-factory.cc
    model/wimax-net-device.cc
    model/bs-net-device.cc
    model/ss-net-device.cc
    model/wimax-mac-header.cc
    model/wimax-phy.cc
    model/wimax-channel.cc
    model/ofdm-downlink-frame-prefix.cc
    model/wimax-connection.cc
    model/ss-record.cc
    model/mac-messages.cc
    model/dl-mac-messages.cc
    model/ul-mac-messages.cc
    model/simple-ofdm-wimax-phy.cc
    model/simple-ofdm-wimax-channel.cc
    model/send-params.cc
    model/ss-manager.cc
    model/connection-manager.cc
    model/bs-uplink-scheduler.cc
    model/bs-uplink-scheduler-simple.cc
    model/bs-uplink-scheduler-mbqos.cc
    model/bs-uplink-scheduler-rtps.cc
    model/bs-scheduler.cc
    model/bs-scheduler-simple.cc
    model/bs-scheduler-rtps.cc
    model/wimax-mac-queue.cc
    model/burst-profile-manager.cc
    model/ss-scheduler.cc
    model/service-flow.cc
    model/service-flow-manager.cc
    model/service-flow-record.cc
    model/ss-link-manager.cc
    model/bs-link-manager.cc
    model/bandwidth-manager.cc
    model/crc8.cc
    model/ul-job.cc
    model/snr-to-block-error-rate-record.cc
    model/snr-to-block-error-rate-manager.cc
    model/simple-ofdm-send-param.cc
    model/ss-service-flow-manager.cc
    model/bs-service-flow-manager.cc
    model/ipcs-classifier.cc
    model/ipcs-classifier-record.cc
    model/wimax-tlv.cc
    model/cs-parameters.cc
    model/wimax-mac-to-mac-header.cc
)

set(header_files
    helper/wimax-helper.h
    model/wimax-channel.h
    model/wimax-net-device.h
    model/bs-net-device.h
    model/ss-net-device.h
    model/cid.h
    model/cid-factory.h
    model/ofdm-downlink-frame-prefix.h
    model/wimax-connection.h
    model/ss-record.h
    model/mac-messages.h
    model/dl-mac-messages.h
    model/ul-mac-messages.h
    model/wimax-phy.h
    model/simple-ofdm-wimax-phy.h
    model/simple-ofdm-wimax-channel.h
    model/send-params.h
    model/service-flow.h
    model/ss-manager.h
    model/connection-manager.h
    model/wimax-mac-header.h
    model/wimax-mac-queue.h
    model/crc8.h
    model/service-flow-manager.h
    model/bs-uplink-scheduler.h
    model/bs-uplink-scheduler-simple.h
    model/bs-uplink-scheduler-mbqos.h
    model/bs-uplink-scheduler-rtps.h
    model/ul-job.h
    model/bs-scheduler.h
    model/bs-scheduler-simple.h
    model/bs-scheduler-rtps.h
    model/service-flow-record.h
    model/snr-to-block-error-rate-record.h
    model/snr-to-block-error-rate-manager.h
    model/simple-ofdm-send-param.h
    model/ss-service-flow-manager.h
    model/bs-service-flow-manager.h
    model/cs-parameters.h
    model/ipcs-classifier-record.h
    model/wimax-tlv.h
    model/ipcs-classifier.h
    model/bvec.h
    model/wimax-mac-to-mac-header.h
)

build_lib(
  LIBNAME wimax
  SOURCE_FILES ${source_files}
  HEADER_FILES ${header_files}
  LIBRARIES_TO_LINK ${libinternet}
                    ${libpropagation}
  TEST_SOURCES
    test/mac-messages-test.cc
    test/phy-test.cc
    test/qos-test.cc
    test/ss-mac-test.cc
    test/wimax-fragmentation-test.cc
    test/wimax-service-flow-test.cc
    test/wimax-tlv-test.cc
)
