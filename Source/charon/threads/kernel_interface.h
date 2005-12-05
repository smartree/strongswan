/**
 * @file kernel_interface.h
 *
 * @brief Interface of kernel_interface_t.
 *
 */

/*
 * Copyright (C) 2005 Jan Hutter, Martin Willi
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#ifndef KERNEL_INTERFACE_H_
#define KERNEL_INTERFACE_H_


#include <network/host.h>
#include <encoding/payloads/proposal_substructure.h>

typedef struct kernel_interface_t kernel_interface_t;

/**
 * @brief 
 * 
 * @ingroup threads
 */
struct kernel_interface_t {

	status_t (*get_spi) (kernel_interface_t *this, host_t *src, host_t *dest, protocol_id_t protocol, bool tunnel_mode, u_int32_t *spi);
	
	status_t (*add_sa)(kernel_interface_t *this,
						host_t *me, 
						host_t *other, 
						u_int32_t spi, 
						int protocol, 
						bool tunnel_mode,
						encryption_algorithm_t enc_alg,
						size_t enc_size,
						chunk_t enc_key,
						integrity_algorithm_t int_alg,
						size_t int_size,
						chunk_t int_key,
						bool replace);
	
	
	/**
	 * @brief Destroys a kernel_interface object.
	 *
	 * Stopps the prime thread and destroys the pool.
	 *
	 * @param kernel_interface_t 	calling object
	 */
	void (*destroy) (kernel_interface_t *kernel_interface);
};

/**
 * @brief 
 * 
 * @ingroup threads
 */
kernel_interface_t *kernel_interface_create();

#endif /*KERNEL_INTERFACE_H_*/
