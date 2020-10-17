message("-- Including test cases...")

set(WORD_DIR ${CMAKE_BINARY_DIR}/../tests)

#add_test(NAME bl_master COMMAND a-team bl_master/mining_bl_master.xml bl_master/bl_master.vcd WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME bl_slave_0 COMMAND a-team bl_slave_0/mining_bl_slave.xml WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME bl_slave_1 COMMAND a-team bl_slave_1/mining_bl_slave.xml WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME camellia COMMAND a-team camellia/mining_camellia.xml camellia/camellia.vcd WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME serial_transmitter COMMAND a-team serial_transmitter/mining_serial_transmitter.xml serial_transmitter/serial_transmitter.vcd WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME testUntil COMMAND a-team testUntil/mining.xml testUntil/mining.xml WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME bridge COMMAND a-team bridge/mining_bridge.xml WORKING_DIRECTORY ${WORD_DIR})

#add_test(NAME arbiter COMMAND a-team arbiter/mining_arbiter.xml arbiter/arbiter.vcd WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME _CC COMMAND a-team _CC/mining_CC.xml WORKING_DIRECTORY ${WORD_DIR})
#add_test(NAME lbdr COMMAND a-team lbdr/mining_lbdr.xml WORKING_DIRECTORY ${WORD_DIR})

#ARB2
#add_test(NAME arb2 COMMAND a-team arbiter_goldmine/mining_arbiter.xml arbiter_goldmine/arb2.vcd WORKING_DIRECTORY ${WORD_DIR})

#HALF ADDER
#add_test(NAME halfadder COMMAND a-team halfadder/mining_halfadder.xml halfadder/halfadder.vcd WORKING_DIRECTORY ${WORD_DIR})

#FIFO
#add_test(NAME fifo_mem COMMAND a-team FIFO/mining_fifo.xml FIFO/fifo_mem.vcd WORKING_DIRECTORY ${WORD_DIR})

#ticatac/fsm_controller
#add_test(NAME fsm_controller COMMAND a-team fsm_controller/mining_fsm_controller.xml fsm_controller/fsm_controller.vcd WORKING_DIRECTORY ${WORD_DIR})

#traffic
#add_test(NAME traffic COMMAND a-team traffic/mining_traffic.xml traffic/traffic.vcd WORKING_DIRECTORY ${WORD_DIR})

#sequence_detector
#add_test(NAME sequence_detector COMMAND a-team sequence_detector/mining_sequence_detector.xml sequence_detector/sequence_detector.vcd WORKING_DIRECTORY ${WORD_DIR})

#sd_cmd_master
#add_test(NAME sd_cmd_master COMMAND a-team sd_cmd_master/mining_sd_cmd_master.xml sd_cmd_master/sd_cmd_master.vcd WORKING_DIRECTORY ${WORD_DIR})

#usbf_idma
#add_test(NAME usbf_idma COMMAND a-team usbf_idma/mining_usbf_idma.xml usbf_idma/usbf_idma.vcd WORKING_DIRECTORY ${WORD_DIR})

#usbf_pe
#add_test(NAME usbf_pa COMMAND a-team usbf_pa/mining_usbf_pa.xml usbf_pa/usbf_pa.vcd WORKING_DIRECTORY ${WORD_DIR})

#machine
add_test(NAME machine COMMAND a-team machine/mining_machine.xml machine/machine.vcd WORKING_DIRECTORY ${WORD_DIR})

#due_otto
#add_test(NAME machine COMMAND a-team due_otto/mining_due_otto.xml due_otto/due_otto.vcd WORKING_DIRECTORY ${WORD_DIR})



