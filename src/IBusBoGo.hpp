/*
  This file is part of IbusBogo.
   Copyright (C) 2012 Long T. Dam <longdt90@gmail.com>
   IbusBogo is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   IbusBogo is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with IbusBogo.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __IBUSBOGO_HPP_
#define __IBUSBOGO_HPP_

#include <ibus.h>
#include <engine.hpp>

#define IBUS_TYPE_BOGO_ENGINE (ibus_bogo_engine_get_type())

GType ibus_bogo_engine_get_type ();

typedef struct _IBusBogoEngine IBusBogoEngine;
typedef struct _IBusBogoEngineClass IBusBogoEngineClass;

struct _IBusBogoEngine {
    IBusEngine parent;
    ustring preedit;
};

struct _IBusBogoEngineClass {
    IBusEngineClass parrent;
};

static void ibus_bogo_engine_class_init  (IBusBogoEngineClass *klass);
static void ibus_bogo_engine_init (IBusBogoEngine *bogo);
static void ibus_bogo_engine_destroy (IBusBogoEngine *bogo);
static void ibus_bogo_engine_process_key_event (IBusEngine *engine,
                                                guint keyval,
                                                guint keycode,
                                                guint modifiers);
static void ibus_bogo_engine_commit_string (IBusBogoEngine *bogo,
                                            const gchar *string);
static void ibus_bogo_engine_update (IbusBogoEngine *bogo);
#endif
