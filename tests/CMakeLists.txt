message("-- Including test cases...")

set(WORD_DIR ${CMAKE_BINARY_DIR}/../tests)

add_test(NAME bl_master COMMAND a-team bl_master/mining_bl_master.xml WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME bl_slave_0 COMMAND a-team bl_slave_0/mining_bl_slave.xml WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME bl_slave_1 COMMAND a-team bl_slave_1/mining_bl_slave.xml WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME camellia COMMAND a-team camellia/mining_camellia.xml WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME transmitter COMMAND a-team transmitter/mining_serial_transmitter.xml WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME testUntil COMMAND a-team testUntil/mining.xml WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME bridge COMMAND a-team bridge/mining_bridge.xml WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME arbiter COMMAND a-team arbiter/mining_arbiter.xml WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME _CC COMMAND a-team _CC/mining_CC.xml WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME lbdr COMMAND a-team lbdr/mining_lbdr.xml WORKING_DIRECTORY ${WORD_DIR})
