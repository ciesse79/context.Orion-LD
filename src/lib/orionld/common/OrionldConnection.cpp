/*
*
* Copyright 2018 Telefonica Investigacion y Desarrollo, S.A.U
*
* This file is part of Orion Context Broker.
*
* Orion Context Broker is free software: you can redistribute it and/or
* modify it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* Orion Context Broker is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero
* General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with Orion Context Broker. If not, see http://www.gnu.org/licenses/.
*
* For those usages not covered by this license please contact with
* iot_support at tid dot es
*
* Author: Ken Zangelin
*/
#include "orionld/common/OrionldConnection.h"                  // OrionldConnectionState



// -----------------------------------------------------------------------------
//
// orionldState - the state of the connection
//
__thread OrionldConnectionState orionldState = { 0 };



// -----------------------------------------------------------------------------
//
// Global state - move all this to another file
//
// Actually, create two new files to replace this one:
// orionldThreadState.cpp/h
// orionldGlobalState.cpp/h
//
int     requestNo = 0;             // Never mind protecting with semaphore. Just a debugging help
char    kallocBuffer[32 * 1024];
KAlloc  kalloc;
Kjson   kjson;
Kjson*  kjsonP;
