/*
 *   Copyright (C) 2016 by Jim McLaughlin KI6ZUM
 *   Copyright (C) 2016, 2017 by Andy Uribe CA6JAU
 *
 *   Some of the code is based on work of Guus Van Dooren PE1PLM:
 *   https://github.com/ki6zum/gmsk-dstar/blob/master/firmware/dvmega/dvmega.ino
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
#if !defined(ADF7021_H)
#define  ADF7021_H

#include "Config.h"

#if defined(ENABLE_ADF7021)

/*
- Most of the registers values are obteined from ADI eval software:
http://www.analog.com/en/products/rf-microwave/integrated-transceivers-transmitters-receivers/low-power-rf-transceivers/adf7021.html
- or ADF7021 datasheet formulas:
www.analog.com/media/en/technical-documentation/data-sheets/ADF7021.pdf
*/

/****** Support for 14.7456 MHz TCXO (modified RF7021SE boards) ******/
#if defined(ADF7021_14_7456)

// R = 4
#define ADF7021_PFD              3686400.0

// PLL (REG 01)
#define ADF7021_REG1_VHF1        0x021F5041
#define ADF7021_REG1_VHF2        0x021F5041
#define ADF7021_REG1_UHF1        0x00575041
#define ADF7021_REG1_UHF2        0x00535041

// Deviation of modulator (REG 02)
#define ADF7021_DEV_DSTAR        43U
#define ADF7021_DEV_DMR          23U
#define ADF7021_DEV_YSF          32U
#define ADF7021_DEV_P25          22U

// TX/RX CLOCK register (REG 03)
#define ADF7021_REG3_DSTAR       0x2A4C4193
#define ADF7021_REG3_DMR         0x2A4C80D3
#define ADF7021_REG3_YSF         0x2A4C80D3
#define ADF7021_REG3_P25         0x2A4C80D3

// Discriminator bandwith, demodulator (REG 04)
// Bug in ADI evaluation software, use datasheet formula (4FSK)
#define ADF7021_DISC_BW_DSTAR    522U // K=85
#define ADF7021_DISC_BW_DMR      393U // K=32
#define ADF7021_DISC_BW_YSF      344U // K=28
#define ADF7021_DISC_BW_P25      394U // K=32

// Post demodulator bandwith (REG 04)
#define ADF7021_POST_BW_DSTAR    10U
#define ADF7021_POST_BW_DMR      65U
#define ADF7021_POST_BW_YSF      20U
#define ADF7021_POST_BW_P25      6U

// IF filter (REG 05)
#define ADF7021_REG5             0x000024F5

// IF CAL (fine cal, defaults) (REG 06)
#define ADF7021_REG6             0x05070E16

// AFC configuration (REG 10)
#if defined(ADF7021_ENABLE_AFC)
#define ADF7021_REG10_DSTAR      0x0C96473A
#define ADF7021_REG10_DMR        0x049E473A
#define ADF7021_REG10_YSF        0x049E473A
#define ADF7021_REG10_P25        0x049E473A
#define AFC_OFFSET_DSTAR         0
#define AFC_OFFSET_DMR           1000
#define AFC_OFFSET_YSF           1000
#define AFC_OFFSET_P25           1000
#else
#define ADF7021_REG10_DSTAR      0x0496472A
#define ADF7021_REG10_DMR        0x049E472A
#define ADF7021_REG10_YSF        0x049E472A
#define ADF7021_REG10_P25        0x049E472A
#define AFC_OFFSET_DSTAR         0
#define AFC_OFFSET_DMR           0
#define AFC_OFFSET_YSF           0
#define AFC_OFFSET_P25           0
#endif

/****** Support for 19.6800 MHz TCXO (original RF7021SE boards) ******/
#elif defined(ADF7021_19_6800)

// R = 4
#define ADF7021_PFD              4920000.0

// PLL (REG 01)
#define ADF7021_REG1_VHF1        0x021F5041
#define ADF7021_REG1_VHF2        0x021F5041
#define ADF7021_REG1_UHF1        0x00575041
#define ADF7021_REG1_UHF2        0x00535041

// Deviation of modulator (REG 02)
#define ADF7021_DEV_DSTAR        32U
#define ADF7021_DEV_DMR          17U
#define ADF7021_DEV_YSF          24U
#define ADF7021_DEV_P25          16U

// TX/RX CLOCK register (REG 03)
#define ADF7021_REG3_DSTAR       0x2B1449E3
#define ADF7021_REG3_DMR         0x2B148123
#define ADF7021_REG3_YSF         0x2B148123
#define ADF7021_REG3_P25         0x2B148123

// Discriminator bandwith, demodulator (REG 04)
// Bug in ADI evaluation software, use datasheet formula (4FSK)
#define ADF7021_DISC_BW_DSTAR    597U // K=85
#define ADF7021_DISC_BW_DMR      393U // K=32
#define ADF7021_DISC_BW_YSF      344U // K=28
#define ADF7021_DISC_BW_P25      394U // K=32

// Post demodulator bandwith (REG 04)
#define ADF7021_POST_BW_DSTAR    10U
#define ADF7021_POST_BW_DMR      65U
#define ADF7021_POST_BW_YSF      20U
#define ADF7021_POST_BW_P25      6U

// IF filter (REG 05)
#define ADF7021_REG5             0x00003155

// IF CAL (coarse cal, defaults) (REG 06)
#define ADF7021_REG6             0x050972C6

// AFC (REG 10)
#if defined(ADF7021_ENABLE_AFC)
#define ADF7021_REG10_DSTAR      0x0C96355A
#define ADF7021_REG10_DMR        0x049E355A
#define ADF7021_REG10_YSF        0x049E355A
#define ADF7021_REG10_P25        0x049E355A
#define AFC_OFFSET_DSTAR         0
#define AFC_OFFSET_DMR           1000
#define AFC_OFFSET_YSF           1000
#define AFC_OFFSET_P25           1000
#else
#define ADF7021_REG10_DSTAR      0x0496354A
#define ADF7021_REG10_DMR        0x049E354A
#define ADF7021_REG10_YSF        0x049E354A
#define ADF7021_REG10_P25        0x049E354A
#define AFC_OFFSET_DSTAR         0
#define AFC_OFFSET_DMR           0
#define AFC_OFFSET_YSF           0
#define AFC_OFFSET_P25           0
#endif

/****** Support for 12.2880 MHz TCXO ******/
#elif defined(ADF7021_12_2880)

// R = 2
#define ADF7021_PFD              6144000.0

// PLL (REG 01)
#define ADF7021_REG1_VHF1        0x021F5021
#define ADF7021_REG1_VHF2        0x021F5021
#define ADF7021_REG1_UHF1        0x00575021
#define ADF7021_REG1_UHF2        0x00535021

// Deviation of modulator (REG 02)
#define ADF7021_DEV_DSTAR        26U
#define ADF7021_DEV_DMR          14U
#define ADF7021_DEV_YSF          19U
#define ADF7021_DEV_P25          14U

// TX/RX CLOCK register (REG 03)
#define ADF7021_REG3_DSTAR       0x29EC4153
#define ADF7021_REG3_DMR         0x29ECA093
#define ADF7021_REG3_YSF         0x29ECA093
#define ADF7021_REG3_P25         0x29ECA093

// Discriminator bandwith, demodulator (REG 04)
// Bug in ADI evaluation software, use datasheet formula (4FSK)
#define ADF7021_DISC_BW_DSTAR    522U // K=85
#define ADF7021_DISC_BW_DMR      491U // K=32
#define ADF7021_DISC_BW_YSF      430U // K=28
#define ADF7021_DISC_BW_P25      493U // K=32

// Post demodulator bandwith (REG 04)
#define ADF7021_POST_BW_DSTAR    10U
#define ADF7021_POST_BW_DMR      65U
#define ADF7021_POST_BW_YSF      20U
#define ADF7021_POST_BW_P25      6U

// IF filter (REG 05)
#define ADF7021_REG5             0x00001ED5

// IF CAL (fine cal, defaults) (REG 06)
#define ADF7021_REG6             0x0505EBB6

// AFC (REG 10)
#if defined(ADF7021_ENABLE_AFC)
#define ADF7021_REG10_DSTAR      0x0C96557A
#define ADF7021_REG10_DMR        0x049E557A
#define ADF7021_REG10_YSF        0x049E557A
#define ADF7021_REG10_P25        0x049E557A
#define AFC_OFFSET_DSTAR         0
#define AFC_OFFSET_DMR           1000
#define AFC_OFFSET_YSF           1000
#define AFC_OFFSET_P25           1000
#else
#define ADF7021_REG10_DSTAR      0x0496556A
#define ADF7021_REG10_DMR        0x049E556A
#define ADF7021_REG10_YSF        0x049E556A
#define ADF7021_REG10_P25        0x049E556A
#define AFC_OFFSET_DSTAR         0
#define AFC_OFFSET_DMR           0
#define AFC_OFFSET_YSF           0
#define AFC_OFFSET_P25           0
#endif

#endif

// Slicer threshold for 4FSK demodulator (REG 13)
#if defined(ADF7021_N_VER)
#define ADF7021_SLICER_TH_DSTAR  0U
#define ADF7021_SLICER_TH_DMR    48U
#define ADF7021_SLICER_TH_YSF    63U
#define ADF7021_SLICER_TH_P25    43U
#else
#define ADF7021_SLICER_TH_DSTAR  0U
#define ADF7021_SLICER_TH_DMR    54U
#define ADF7021_SLICER_TH_YSF    75U
#define ADF7021_SLICER_TH_P25    52U
#endif

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)

void Send_AD7021_control(void);

#endif

#endif