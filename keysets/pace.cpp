//
// pace.cpp
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "pace.h"
#include "protocols/nokia32protocol.h"

PaceSTB1::PaceSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Pace_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void PaceSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated
    return;
  }

  threadableProtocol = new Nokia32Protocol(guiObject, index);

  setPreData(0x20C0, 16);
  setPostData(0x26, 7);

  addKey("0", Zero_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("power", Power_Key, 0x0C, 8);
  addKey("mute", Mute_Key, 0x0D, 8);
  addKey("vol up", VolumeUp_Key, 0x10, 8);
  addKey("vol down", VolumeDown_Key, 0x11, 8);
  addKey("channel up", ChannelUp_Key, 0x20, 8);
  addKey("channel down", ChannelDown_Key, 0x21, 8);
  addKey("fast fwd", FastForward_Key, 0x28, 8);
  addKey("rewind", Rewind_Key, 0x29, 8);
  addKey("play", Play_Key, 0x2C, 8);
  addKey("pause", Pause_Key, 0x30, 8);
  addKey("stop", Stop_Key, 0x31, 8);
  addKey("record", Record_Key, 0x37, 8);
  addKey("upc", Unmapped_Key, 0x38, 8);
  addKey("tv/radio", Unmapped_Key, 0x39, 8);
  addKey("teletext", Unmapped_Key, 0x3C, 8);
  addKey("last(prev ch)", PrevChannel_Key, 0x4D, 8);
  addKey("up arrow", Up_Key, 0x58, 8);
  addKey("down arrow", Down_Key, 0x59, 8);
  addKey("left arrow", Left_Key, 0x5A, 8);
  addKey("right arrow", Right_Key, 0x5B, 8);
  addKey("select", Select_Key, 0x5C, 8);
  addKey("red", Red_Key, 0x6D, 8);
  addKey("green", Green_Key, 0x6E, 8);
  addKey("yellow", Yellow_Key, 0x6F, 8);
  addKey("blue", Blue_Key, 0x70, 8);
  addKey("help", Unmapped_Key, 0x81, 8);
  addKey("display", Info_Key, 0xCB, 8);
  addKey("program guide", Guide_Key, 0xCC, 8);
  addKey("page+", PageDown_Key, 0xCE, 8);
  addKey("page-", PageUp_Key, 0xCF, 8);
  addKey("interactive", Unmapped_Key, 0xD7, 8);
  addKey("menu", Menu_Key, 0xDB, 8);
  addKey("ondemand", Unampped_Key, 0xF5, 8);
}
