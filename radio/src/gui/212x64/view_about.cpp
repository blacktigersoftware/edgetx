/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x 
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "opentx.h"

#define ABOUT_INDENT 6

const char ABOUT_VERSION_1[] = "EdgeTX Endeavour (2.4.0)";
const char ABOUT_VERSION_2[] = "Copyright (C) 2021 EdgeTX";
const char ABOUT_VERSION_3[] = "https://edge-tx.org";

void menuAboutView(event_t event)
{
  switch(event)
  {
    case EVT_KEY_FIRST(KEY_ENTER):
    case EVT_KEY_FIRST(KEY_EXIT):
      chainMenu(menuMainView);
      break;
  }

  lcdDrawText(2, 2, STR_ABOUTUS, BOLD);
  lcdDrawSolidHorizontalLine(0, 11, 130, GREY_DEFAULT);

  lcdDrawText(ABOUT_INDENT, 22, ABOUT_VERSION_1);
  lcdDrawText(ABOUT_INDENT, 32, ABOUT_VERSION_2, SMLSIZE);
  lcdDrawText(ABOUT_INDENT, 42, ABOUT_VERSION_3);
}
