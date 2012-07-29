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

#include <ibus.h>
#include "IBusBoGo.hpp"

#define PKGDATADIR "."

static IBusBus *bus = NULL;
static IBusFactory *factory = NULL;

    /* command line options */
static gboolean ibus = FALSE;
static gboolean verbose = FALSE;

static const GOptionEntry entries[] = {
    { "ibus", 'i', 0, G_OPTION_ARG_NONE, &ibus, "component is executed by ibus", NULL },
    { "verbose", 'v', 0, G_OPTION_ARG_NONE, &verbose, "verbose", NULL },
    { NULL },
};

static void ibus_disconnected_cb (IBusBus  *bus, gpointer  user_data) {
    ibus_quit ();
}


static void init (void) {
    ibus_init ();

    bus = ibus_bus_new ();
    g_object_ref_sink (bus);
    g_signal_connect (bus, "disconnected", G_CALLBACK (ibus_disconnected_cb), NULL);

    factory = ibus_factory_new (ibus_bus_get_connection (bus));
    g_object_ref_sink (factory);
    ibus_factory_add_engine (factory, "bogo", IBUS_TYPE_BOGO_ENGINE);

    if (ibus) {
        ibus_bus_request_name (bus, "org.freedesktop.IBus.BoGo", 0);
    }
    else {
        IBusComponent *component;

        component = ibus_component_new ("org.freedesktop.IBus.BoGo",
                                        "BoGo",
                                        "0.1.0",
                                        "GPLv3",
                                        "Long T. Dam <longdt90@gmail.com>",
                                        "https://github.com/milkycoffee",
                                        "",
                                        "IBusBoGoEngine");
        ibus_component_add_engine (component,
                                   ibus_engine_desc_new ("bogo",
                                                         "BoGo",
                                                         "BoGo",
                                                         "ko",
                                                         "GPLv3",
                                                         "Long T. Dam <longdt90@gmail.com",
                                                         PKGDATADIR"/icons/ibus-bogo.svg",
                                                         "us"));
        ibus_bus_register_component (bus, component);
    }
}

int main(int argc, char **argv) {
    GError *error = NULL;
    GOptionContext *context;

    /* Parse the command line */
    context = g_option_context_new ("- ibus template engine");
    g_option_context_add_main_entries (context, entries, "ibus-tmpl");

    if (!g_option_context_parse (context, &argc, &argv, &error)) {
      g_print ("Option parsing failed: %s\n", error->message);
      g_error_free (error);
      return (-1);
    }

    /* Go */
    init ();
    ibus_main ();
}
