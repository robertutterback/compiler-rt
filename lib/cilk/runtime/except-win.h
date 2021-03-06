/* except-win.h                  -*-C++-*-
 *
 *************************************************************************
 *
 *  Copyright (C) 2009-2015, Intel Corporation
 *  All rights reserved.
 *  
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 *    * Neither the name of Intel Corporation nor the names of its
 *      contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 *  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 *  WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *  
 *  *********************************************************************
 *  
 *  PLEASE NOTE: This file is a downstream copy of a file mainitained in
 *  a repository at cilkplus.org. Changes made to this file that are not
 *  submitted through the contribution process detailed at
 *  http://www.cilkplus.org/submit-cilk-contribution will be lost the next
 *  time that a new version is released. Changes only submitted to the
 *  GNU compiler collection or posted to the git repository at
 *  https://bitbucket.org/intelcilkplusruntime/itnel-cilk-runtime.git are
 *  not tracked.
 *  
 *  We welcome your contributions to this open source project. Thank you
 *  for your assistance in helping us improve Cilk Plus.
 **************************************************************************/

/**
 * @file except-win.h
 *
 * @brief Common declarations for exception handling on Windows
 */

#ifndef INCLUDED_EXCEPT_WIN_DOT_H
#define INCLUDED_EXCEPT_WIN_DOT_H

/**
 * throw statements are converted into calls to _CxxThrowException(), which
 * actually raises a Win32 (SEH) exception with the code 0xE06D7363
 * ('msc'|0xE0000000).
 */
#define CXX_EXCEPTION 0xE06d7363

/// Magic number used to indicate exception handling structures generated by
/// compilers up to VC6
#define EH_MAGIC_NUMBER1 0x19930520

/// Magic number used to indicate exception handling structures generated by
/// compilers VC7 compilers
#define EH_MAGIC_NUMBER2 0x19930521

/// Magic number used to indicate exception handling structures generated by
/// compilers up to VC8 compilers or later
#define EH_MAGIC_NUMBER3 0x19930522

/**
 * Run Time Type Inforation (RTTI) type descriptor.
 *
 * Describes a single C++ type. Used here to match the thrown exception type
 * with catch type.
 */
typedef struct
{
    /// vtable of type_info class
    const void * pVFTable;

    /// used to keep the demangled name returned by type_info::name()
    void *spare;

    /// mangled type name, e.g. ".H" = "int", ".?AUA@@" = "struct A", ".?AVA@@" = "class A"
    char name[1];
} TypeDescriptor;

/**
 * Generalized Pointer to Member Descriptor
 */
typedef struct
{
    /// Member offset
    int mdisp;

    /// Offset of the vtable (-1 if not a virtual base)
    int pdisp;

    /// Offset to the displacement value inside the vtable
    int vdisp;
} PMD;


#endif // ! defined(INCLUDED_EXCEPT_WIN_DOT_H)
