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

int __attribute__((fastcall)) strconcat(const char *s1, const char *s2)
{
  while (*s1 && *s2) {
    s1++;
    s2++;
  }
  return (*s1 + *s2);
}


