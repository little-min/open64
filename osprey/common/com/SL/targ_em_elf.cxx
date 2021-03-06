/********************************************************************\
|*                                                                  *|   
|*  Copyright (c) 2006 by SimpLight Nanoelectronics.                *|
|*  All rights reserved                                             *|
|*                                                                  *|
|*  This program is free software; you can redistribute it and/or   *|
|*  modify it under the terms of the GNU General Public License as  *|
|*  published by the Free Software Foundation; either version 2,    *|
|*  or (at your option) any later version.                          *|
|*                                                                  *|
\********************************************************************/

/* ====================================================================
 * ====================================================================
 *
 * Module: em_elf.c
 * $Revision: 1.6 $
 * $Date: 05/12/05 08:59:43-08:00 $
 * $Author: bos@eng-24.pathscale.com $
 * $Source: /scratch/mee/2.4-65/kpro64-pending/common/com/x8664/SCCS/s.targ_em_elf.cxx $
 *
 * Description:
 *
 * Generate the elf headers and sections for the object file.
 *
 * ====================================================================
 * ====================================================================
 */


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <bstring.h>
#include "elf_stuff.h"
#include <elfaccess.h>
#include "libelf/libelf.h"
#include <stamp.h>
#include <alloca.h>
#include <cmplrs/leb128.h>
#include <cmplrs/elf_interfaces.h>
#include <sys/unwindP.h>

#define	USE_STANDARD_TYPES 1
#include "defs.h"
#include "erlib.h"
#include "erglob.h"
#include "config.h"
#include "targ_const.h"
#include "glob.h"
#include "config.h"
#include "config_elf_targ.h"
#include "em_elf.h"

INT GP_DISP = 0;

pSCNINFO Interface_Scn;

void Em_Write_Reginfo (
    Elf64_Addr gprvalue, 
    Elf64_Word gprmask, 
    Elf64_Word fprmask,
    BOOL pure_abi)
{
    /* should we put reginfo into the .options section? */
    /* A:  no */
    return;

}

/* Add new entry to the .options section. */
void
Em_Add_New_Option (
    Elf32_Byte option_kind, 
    Elf32_Section option_section, 
    Elf32_Word option_info, 
    void *buffer, 
    Elf32_Byte length)
{
    Elf_Options option;
    return;
}


/* Add a new event to the .events section. The operand1 and operand2
   parameters are used to pass additional information needed for 
   certain event kinds.

     EK_IF_ENTRY:		operand1 is offset in interface scn.

     EK_FCALL_LOCAL,
     EK_FCALL_EXTERN,
     EX_FCALL_EXTERN_BIG:	operand1 is elf symbol index of called proc.
*/
void
Em_Add_New_Event (
    Elf64_Word ev_kind, 
    Elf64_Word ev_ofst, 
    Elf64_Word operand1,
    Elf64_Word operand2,
    Elf64_Word operand3,
    pSCNINFO scn)
{
  return;
}


/* Add a new entry to the .contents section. */
void
Em_Add_New_Content (
    Elf64_Word con_kind, 
    Elf64_Xword con_ofst, 
    Elf64_Word operand1,
    Elf64_Word operand2,
    pSCNINFO scn)
{
  return;
}

void
Em_End_Unwind (FILE *trace_file, pSCNINFO text_scn)
{
  if (trace_file) {
	// dump unwind table and unwind info
	// should be trace file
        unwind_process (unwind_dump2ascii, (void *) trace_file);
  }
  unwind_process (unwind_dump2elf, text_scn);
}

void
Em_Cleanup_Unwind (void)
{
}

