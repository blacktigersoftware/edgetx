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

#include "layout.h"
#include "layout_factory_impl.h"

const uint8_t LBM_LAYOUT_2x1[] = {
#include "mask_layout2x1.lbm"
};

const ZoneOption OPTIONS_LAYOUT_2x1[] =  {
  LAYOUT_COMMON_OPTIONS,
  LAYOUT_OPTIONS_END
};

class Layout2x1: public Layout
{
  public:
    Layout2x1(const LayoutFactory * factory, Layout::PersistentData * persistentData):
      Layout(factory, persistentData)
    {
    }

    unsigned int getZonesCount() const override
    {
      return 2;
    }

    rect_t getZone(unsigned int index) const override
    {
      rect_t zone = getMainZone();

      if (index == 0) {
        return {isMirrored() ? zone.x + zone.w / 2 : zone.x, zone.y, zone.w / 2, zone.h};
      }
      else {
        return {isMirrored() ? zone.x : zone.x + zone.w / 2, zone.y, zone.w / 2, zone.h};
      }

      return zone;
    }
};

BaseLayoutFactory<Layout2x1> Layout2x1("Layout2x1", "2 x 1", LBM_LAYOUT_2x1, OPTIONS_LAYOUT_2x1);
