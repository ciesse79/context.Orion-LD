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
extern "C"
{
#include "kjson/KjNode.h"                                      // KjNode, kjValueType
}

#include "logMsg/logMsg.h"                                     // LM_*
#include "logMsg/traceLevels.h"                                // Lmt*

#include "orionld/context/orionldContextList.h"                // orionldContextHead, orionldContextTail, orionldContextListSemTake/Give
#include "orionld/context/orionldContextListInsert.h"          // Own Interface



// ----------------------------------------------------------------------------
//
// orionldContextListInsert -
//
void orionldContextListInsert(OrionldContext* contextP, bool semAlreadyTaken)
{
  LM_T(LmtContextList, ("Adding context '%s' to the list (context at %p, tree at %p)", contextP->url, contextP, contextP->tree));

  if (semAlreadyTaken == false)
    orionldContextListSemTake(__FILE__);

  if (orionldContextHead == NULL)
  {
    orionldContextHead = contextP;
    orionldContextTail = contextP;
  }
  else
  {
    orionldContextTail->next = contextP;
    orionldContextTail       = contextP;
  }

  contextP->next      = NULL;
  contextP->temporary = false;

  //
  // Presenting the list  (TMP)
  //
  LM_TMP(("-------------------------------------------------------------------------------------------------------"));
  LM_TMP(("Current context LIST:"));
  for (OrionldContext* ctxP = orionldContextHead; ctxP != NULL; ctxP = ctxP->next)
  {
    if (ctxP->tree->value.firstChildP->value.firstChildP != NULL)
      LM_TMP(("o %p: tree:%p, next:%p, url:%s, type:%s/%s/%s", ctxP, ctxP->tree, ctxP->next, ctxP->url,
              kjValueType(ctxP->tree->type),
              kjValueType(ctxP->tree->value.firstChildP->type),
              kjValueType(ctxP->tree->value.firstChildP->value.firstChildP->type)));
    else if (ctxP->tree->value.firstChildP != NULL)
      LM_TMP(("o %p: tree:%p, next:%p, url:%s, type:%s/%s", ctxP, ctxP->tree, ctxP->next, ctxP->url,
              kjValueType(ctxP->tree->type),
              kjValueType(ctxP->tree->value.firstChildP->type)));
    else
      LM_TMP(("o %p: tree:%p, next:%p, url:%s, type:%s", ctxP, ctxP->tree, ctxP->next, ctxP->url,
              kjValueType(ctxP->tree->type)));
  }
  LM_TMP(("-------------------------------------------------------------------------------------------------------"));
  LM_TMP((""));

  if (semAlreadyTaken == false)
    orionldContextListSemGive(__FILE__);
}
