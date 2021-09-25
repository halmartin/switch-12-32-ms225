/*
 * Copyright (C) 2013, Broadcom Corporation. All Rights Reserved.
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Broadcom Home Networking Division 10/100 Mbit/s Ethernet
 * Helix4 sudo EROM
 *
 */
#include <typedefs.h>

uint32 hr2_erom[] = {
	//#define CC_CORE_ID		0x800		/* chipcommon core */
	0x4bf80001, 0x2a004201, 0x18000005, 0x181200c5,
	//#define NS_CCB_CORE_ID		0x50b		/* ChipcommonB core */
	0x4bf50b01, 0x01000201, 0x18001005, 0x18002005, 0x18003005, 0x18004005, 0x18005005, 0x18006005, 0x18007005, 0x18008005, 0x18009005,
	//#define NS_DMA_CORE_ID		0x502		/* DMA core */
	0x4bf50201, 0x01004211, 0x00000003, 0x1802c005, 0x181140c5,
	//#define	GMAC_CORE_ID		0x82d		/* Gigabit MAC core */
	0x4bf82d01, 0x04004211, 0x00000103, 0x18022005, 0x181100c5,
	//#define NS_PCIEG2_CORE_ID	0x501		/* PCIE Gen 2 core */
	0x4bf50101, 0x01084411, 0x00000503, 0x18012005, 0x08000135, 0x08000000, 0x181010c5, 0x1810a185,
	0x4bf50101, 0x01084411, 0x00000603, 0x18013005, 0x40000135, 0x08000000, 0x181020c5, 0x1810b185,
	0x4bf50101, 0x01084411, 0x00000703, 0x18014005, 0x48000135, 0x08000000, 0x181030c5, 0x1810c185,
	//#define	ARMCA9_CORE_ID		0x510		/* ARM Cortex A9 core (ihost) */
	0x4bf51001, 0x01104611, 0x00000803, 0x1800b005, 0x1800c005, 0x19000135, 0x00020000, 0x19020235, 0x00003000, 0x181000c5, 0x18106185, 0x18107285,
	//#define NS_USB20_CORE_ID	0x504		/* USB2.0 core */
	0x4bf50401, 0x01004211, 0x00000903, 0x18021005, 0x18022005, 0x181150c5,
	//#define NS_USB30_CORE_ID	0x505		/* USB3.0 core */
	0x4bf50501, 0x01004211, 0x00000a03, 0x18023005, 0x181050c5,
	//#define NS_SDIO3_CORE_ID	0x503		/* SDIO3 core */
	0x4bf50301, 0x01004211, 0x00000b03, 0x18020005, 0x181160c5,
	//#define	I2S_CORE_ID		0x834		/* I2S core */
	0x4bf83401, 0x03004211, 0x00000c03, 0x1802a005, 0x181170c5,
	//#define NS_A9JTAG_CORE_ID	0x506		/* ARM Cortex A9 JTAG core */
	0x4bf50601, 0x01084211, 0x00000d03, 0x18210035, 0x00010000, 0x181180c5, 0x1811c085,
	//#define NS_DDR23_CORE_ID	0x507		/* Denali DDR2/DDR3 memory controller */
	0x4bf50701, 0x01100601, 0x18010005, 0x00000135, 0x08000000, 0x80000135, 0x30000000, 0xb0000235, 0x10000000, 0x18108185, 0x18109285,
	//#define NS_ROM_CORE_ID		0x508		/* ROM core */
	0x4bf50801, 0x01080201, 0xfffd0035, 0x00030000, 0x1810d085,
	//#define NS_NAND_CORE_ID		0x509		/* NAND flash controller core */
	0x4bf50901, 0x01080401, 0x18028005, 0x1c000135, 0x02000000, 0x1811a185,
	//#define NS_QSPI_CORE_ID		0x50a		/* SPI flash controller core */
	0x4bf50a01, 0x01080401, 0x18029005, 0x1e000135, 0x02000000, 0x1811b185,
	//#define EROM_CORE_ID		0x366		/* EROM core ID */
	0x43b36601, 0x00000201, 0x18130005,
	0x43b13501, 0x00080201, 0x18000075, 0x00010000, 0x18121085,
	0x43b30101, 0x01000201, 0x1a000035, 0x00100000,
	0x43bfff01, 0x00280a01, 0x10000035, 0x08000000, 0x18011005, 0x18015035, 0x0000b000, 0x1802b105, 0x1802d135, 0x000d3000, 0x18104105, 0x1810e215,
				0x18119205, 0x1811d235, 0x00003000, 0x18122335, 0x0000e000, 0x18131305, 0x18137335, 0x000d9000, 0x18220335, 0x000de000, 0x19023335,
				0x00fdd000, 0x1a100335, 0x01f00000, 0x20000435, 0x20000000, 0x50000435, 0x30000000, 0xc0000435, 0x3ffd0000, 0x18132085, 0x18133185,
				0x18134285, 0x18135385, 0x18136485,
	0x0000000f
};
