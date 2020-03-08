/*
 *######################################################################
 *                                RAppIDJDP
 *           Rapid Application Initialization and Documentation Tool
 *                         ST MicroElectronics.
 *                (c) Copyright 2004-2008 ST MicroElectronics.
 *                         ALL RIGHTS RESERVED.
 *                        SPC560P50 Configuration Tool 
 *######################################################################
 *
 * Project Name           : Pictus_Flash
 *
 * Project File           : Pictus_Flash.rsp
 *
 * Revision Number        : 1.0
 *
 * Tool Version           : 1.1.0.3
 *
 * file                   : bam_init.c
 *
 * Target Compiler        : Diab
 *
 * Target Part            : SPC560P50
 *
 * Part Errata Fixes      : none
 *
 * Project Last Save Date : 16-Sep-2009 09:44:44
 *
 * Created on Date        : 16-Sep-2009 09:44:47
 *
 * Brief Description      : File contains RCHW initialization
 *
 ******************************************************************************** 
 *
 * Detail Description     : This file contains the Bootup Reset Config Half Word(RCHW)initialization.
 *                          This file pushed control on reset to crt0.s start function.
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 
#pragma section SCONST ".rcw" ".urcw"
#pragma use_section SCONST

 const long int ResetConfigWord =  0x005A0000;             
        /* BOOTID: Boot Identifier is 0x005A0000*/
extern const void _start();

const int _reset = (int)_start;
 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

