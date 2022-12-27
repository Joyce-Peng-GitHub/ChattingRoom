#pragma once

#include <string>
#include <array>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/integer.hpp>

namespace chatting_room {
	class server {
	public:
		static const boost::asio::ip::port_type default_port = 32768u;
		static const std::array<char, 7> default_record_file_name = "record";

		server(boost::asio::ip::port_type port = default_port) :
			acceptor(this->io_service,
				boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {

		}
		void init(boost::asio::ip::port_type port = default_port) {
			this->acceptor = boost::asio::ip::tcp::acceptor(
				this->io_service,
				boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)
			);
		}

	protected:
		boost::asio::io_service io_service;
		boost::asio::ip::tcp::acceptor acceptor;
	private:
	};
}