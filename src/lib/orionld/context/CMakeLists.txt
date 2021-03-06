# Copyright 2018 FIWARE Foundation 
#
# This file is part of Orion-LD Context Broker.
#
# Orion Context Broker is free software: you can redistribute it and/or
# modify it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# Orion Context Broker is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero
# General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with Orion Context Broker. If not, see http://www.gnu.org/licenses/.
#
# For those usages not covered by this license please contact with
# iot_support at tid dot es

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET (SOURCES
    orionldContextList.cpp
    orionldContextAdd.cpp
    orionldContextCreateFromTree.cpp
    orionldContextCreateFromUrl.cpp
    orionldContextListInsert.cpp
    orionldContextLookup.cpp
    orionldContextItemLookup.cpp
    orionldContextFree.cpp
    orionldContextFreeAll.cpp
    orionldContextDownloadAndParse.cpp
    orionldCoreContext.cpp
    orionldContextPresent.cpp
    orionldContextValueLookup.cpp
    orionldContextAppend.cpp
    orionldContextListPresent.cpp
    orionldUserContextKeyValuesCheck.cpp
    orionldContextTreat.cpp
    orionldUriExpand.cpp
    orionldAliasLookup.cpp
)

# Include directories
# -----------------------------------------------------------------
include_directories("${PROJECT_SOURCE_DIR}/src/lib")


# Library declaration
# -----------------------------------------------------------------
ADD_LIBRARY(orionld_context STATIC ${SOURCES})
