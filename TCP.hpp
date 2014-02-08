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
	Socket(int mode);//socket()
	~Socket();//shutdown()
};

class socketUDP:public Socket{
	private:
	public:		SocketUDP();
			~SocketUDP();
			bool invia(char*,Address*);//send()
			char* ricevi(Address*);//recv()
}; 

class ClientUDP:public Socket{
	private:
	public:		ClientUDP();
			~ClientUDP();
			
};

class ServerUDP:public Socket{
	private:
	public:		ServerUDP(int port);
			~ClientUDP();
			
};

class SocketTCP::public Socket {
	public:		SocketTCP();
			~SocketTCP();
}; 

class ClientTCP:public Socket{	
	private:	Connessione* connessione;
	public:		ClientTCP();
			~ClientTCP();
			bool connetti(Address* server);//connect()
			bool close_connessione();
			bool invia(char* msg);
			char* ricevi()/*{
					return connessione->ricevi();
				      }*/;
};
class ServerTCP:Public Socket
	private:	Lista* lista_connessioni;
	public:		ServerTCP(int port);//bind()-listen()
			~ServerTCP();
			Connessione* accettata();
			void close_tutte_connessioni();
			void invia_a_tutti(char* msg);
};

class Nodo{
	private:	Nodo* _next;
	public:		Nodo(Nodo* next);
			~Nodo();		
			void set_next(Nodo*);
			Nodo* get_next();
};

class Iterator;

class Lista{
	private:	Nodo* first;
			void remove_Node(Nodo* curr) {
							if (curr){
								remove_Node(curr->get_next());
								deletedelete(curr);
							}
						     }
	public:		Lista();
			~Lista(){remove_Node(first);}
			Nodo* add_node(Nodo*);
			Iterator* create_iterator();
};			

class Iterator{
	private:	Lista* lista;
			Nodo* current;
	public:		Iterator(Lista* lista);
			~Iterator();
			Nodo* get_current();
			Nodo* move_next();
			Nodo* move_first();
			bool is_done;
};
		
class Connessione:public Nodo {
	private:	int conn_id;
	public:		Connessione(int conn_id);
			~Connessione();
			bool invia(char* msg);//send()
			char* ricevi();//recv()
};
				
class Conn_Client:public Connessione {
	public:		Conn_Client(int sock_id);
			~Conn_Client();//cippa
};

class Conn_Server:public Connessione {
	public:		Conn_Server(int conn_id);
			~Conn_Server();//close()
};


/*Iterator* it;
for( it=lista->create_Iterator();elemento = it->move_next(); elemento->do_something())*/
