if(CONFIG_ERPC)
zephyr_interface_library_named(ERPC)

zephyr_include_directories(ERPC INTERFACE erpc_c/config erpc_c/infra eprc_c/port erpc_c/setup
	erpc_c/transports)
zephyr_library()
zephyr_library_sources(
	erpc_c/infra/erpc_basic_codec.cpp
	erpc_c/infra/erpc_client_manager.cpp
	erpc_c/infra/erpc_crc16.cpp
	erpc_c/infra/erpc_framed_transport.cpp
	erpc_c/infra/erpc_message_buffer.cpp
	erpc_c/infra/erpc_message_loggers.cpp
	erpc_c/infra/erpc_server.cpp
	erpc_c/infra/erpc_simple_server.cpp
	erpc_c/infra/erpc_transport_arbitrator.cpp
	erpc_c/port/erpc_port_stdlib.cpp
	erpc_c/port/erpc_threading_pthreads.cpp
	erpc_c/port/erpc_serial.cpp
	erpc_c/setup/erpc_arbitrated_client_setup.cpp
	erpc_c/setup/erpc_client_setup.cpp
	erpc_c/setup/erpc_server_setup.cpp
	erpc_c/setup/erpc_setup_serial.cpp
	erpc_c/transports/erpc_inter_thread_buffer_transport.cpp
	erpc_c/transports/erpc_serial_transport.cpp
	erpc_c/transports/erpc_tcp_transport.cpp
)

zephyr_library_link_libraries(ERPC)
zephyr_link_libraries(ERPC INTERFACE zephyr_interface)
endif()

