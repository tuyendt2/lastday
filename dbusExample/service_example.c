    #include <stdio.h>

    #include <dbus/dbus.h>

    int main()

    {

    DBusConnection *connection;

    DBusError error;

     

    dbus_error_init(&error);

    connection = dbus_bus_DBUS_BUS_STARTER, &error); /* DBUS_BUS_STARTER is

    the bus that started us */

    /* Do something here to make sure that the application was successfully

    started by DBus

    * Example could be something like

    * FILE *tmp;

    * tmp = fopen("/tmp/share-linux-service.result", "w");

    * fprintf(tmp,"share-linux service was started successfully");

    * fclose(tmp);

    * /

     

    /* After that you have the service up, so you can do whetever you like */

    dbus_connection_unref(connection);

     

    return 0;

    }