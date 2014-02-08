/*
 * TCP.hpp
 * This file is part of Vallaurisoft
 *
 * Copyright (C) 2014 - Ferrari
 *
 * Vallaurisoft is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Vallaurisoft is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Vallaurisoft; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */

class Socket {
	private int sock_id;
	Socket(int mode);
	~Socket();
};

class socketUDP::public Socket{
	private:
	public:		SocketUDP();
			~SocketUDP();
			bool invia(char*,Address*);
			char* ricevi(Address*);
}; 

class ClientUDP::public Socket{
	private:
	public:		ClientUDP();
			~ClientUDP();
			
};

class ServerUDP::public Socket{
	private:
	public:		ServerUDP(int port);
			~ClientUDP();
			
};

class SocketTCP::public Socket {
	public:		SocketUDP();
			~SocketUDP();
}; 

class ClientTCP::public Socket{	
	private:	Connessione* connessione;
	public:		ClientTCP();
			~ClientTCP();
			bool connetti(Address* server);
			bool close_connessione();
			bool invia(char* msg);
			char* ricevi();
};
class ServerTCP::Public Socket
	private:	Lista* lista_connessioni;
	public:		ClientTCP(int port);
			~ClientTCP();
			Connessione* accettata();
			void close_tutte_connessioni();
};			

class Connessione{
	private:	int conn_id;
			
