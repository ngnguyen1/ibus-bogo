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

#include "IBusBoGo.hpp"

G_DEFINE_TYPE (IBusBogoEngine, ibus_bogo_engine, IBUS_TYPE_ENGINE);

static void ibus_bogo_engine_class_init  (IBusBogoEngineClass *klass) {
    IBusObjectClass * ibus_object_class = IBUS_OBJECT_CLASS (klass);
    IBusEngineClass * engine_class = IBUS_ENGINE_CLASS (klass);

    ibus_object_class -> destroy = 
        (IBusObjectDestroyFunc) ibus_bogo_engine_destroy;

    engine_class -> process_key_event = ibus_bogo_engine_process_key_event;

};
static void ibus_bogo_engine_init (IBusBogoEngine *bogo) {
    
};
static void ibus_bogo_engine_destroy (IBusBogoEngine *bogo) {};
