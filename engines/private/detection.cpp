/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "base/plugins.h"
#include "engines/advancedDetector.h"

namespace Private {
static const PlainGameDescriptor privateGames[] = {
    { "private-eye", "Private Eye" },
    { 0, 0 }
};


static const ADGameDescription gameDescriptions[] = {
    {
        "private-eye",  // US release
        0,
        AD_ENTRY1s("ASSETS.Z", "3a7532349cda8126e96dd5e49884af3a", 40232),
        Common::EN_USA,
        Common::kPlatformWindows,
        ADGF_NO_FLAGS,
        GUIO1(GUIO_NOMIDI)
    },

    {
        "private-eye",  // EU release
        0,
        AD_ENTRY1s("ASSETS.Z", "73874f969026d6fd21a4e9834ce4a1a7", 17695),
        Common::EN_GRB,
        Common::kPlatformWindows,
        ADGF_UNSUPPORTED,
        GUIO1(GUIO_NOMIDI)
    },

    {
        "private-eye", // Demo from archive.org
        "Demo",
        AD_ENTRY1s("ASSETS.Z", "854e141bb67535359620a1833fcc1566", 5955),
        Common::EN_USA,
        Common::kPlatformWindows,
        ADGF_DEMO,
        GUIO1(GUIO_NOMIDI)
    },

    {
        "private-eye", // Demo from the US release
        "Demo",
        AD_ENTRY1s("ASSETS.Z", "045766e39f44d6ee3bf92f0d4521587c", 5961),
        Common::EN_USA,
        Common::kPlatformWindows,
        ADGF_DEMO,
        GUIO1(GUIO_NOMIDI)
    },


    {
        "private-eye", // Demo from the EU release
        "Demo",
        AD_ENTRY1s("ASSETS.Z", "15e10e8fbb1e9aac4d32c5d8215e7c86", 2299),
        Common::EN_GRB,
        Common::kPlatformWindows,
        ADGF_DEMO | ADGF_UNSUPPORTED,
        GUIO1(GUIO_NOMIDI)
    },

    AD_TABLE_END_MARKER
};
} // End of namespace Private

static const char *const directoryGlobs[] = {
    "SUPPORT",
    0
};

class PrivateMetaEngineDetection : public AdvancedMetaEngineDetection {
public:
    PrivateMetaEngineDetection() : AdvancedMetaEngineDetection(Private::gameDescriptions, sizeof(ADGameDescription), Private::privateGames) {
        _maxScanDepth = 2;
        _directoryGlobs = directoryGlobs;
    }

    const char *getEngineId() const override {
        return "private";
    }

    const char *getName() const override {
        return "Private Eye";
    }

    const char *getOriginalCopyright() const override {
        return "Copyright (C) Brooklyn Multimedia";
    }
};

REGISTER_PLUGIN_STATIC(PRIVATE_DETECTION, PLUGIN_TYPE_ENGINE_DETECTION, PrivateMetaEngineDetection);