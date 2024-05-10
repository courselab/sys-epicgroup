/*
 *    SPDX-FileCopyrightText: 2021 Monaco F. J. <monaco@usp.br>
 *    SPDX-FileCopyrightText: 2024 Pedro Lucas Castro de Andrade <pedroandrade@usp.br>
 *   
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative work from SYSeg (https://gitlab.com/monaco/syseg)
 *  and contains modifications carried out by the following author(s):
 *  Pedro Lucas Castro de Andrade <pedroandrade@usp.br>
 */

#ifndef BIOS_H
#define BIOS_H

void __attribute__((fastcall)) clear (void);
void __attribute__((fastcall)) print();
void __attribute__((fastcall)) println();
void __attribute__((fastcall)) readln(char *);


#endif
