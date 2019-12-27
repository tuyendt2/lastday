    #include <stdio.h>
	#include <stdlib.h>
    #include <dbus/dbus.h>
	#include <string.h>
    int main(int argc, char *argv[])

    {

    DBusConnection *connection;

    DBusError error;
	/*
     printf("argv[0] = %s\n",argv[0]);
	 printf("argv[1] = %s\n",argv[1]);
	 printf("argv[2] = %s\n",argv[2]);
	 printf("argc = %d\n",argc);
	*/
    char *name = "org.share.linux";
	
	if(argc > 1){
		name = (char *)malloc(strlen(argv[1])*sizeof(char*));
		strcpy(name,argv[1]);
	}
	

    dbus_error_init(&error);
	
	printf("DbusError init name = %s, message = %s\n ",error.name,error.message);

    connection = dbus_bus_DBUS_BUS_SESSION, &error);
	
	printf("DbusError init name = %s, message = %s\n ",error.name,error.message);

    if ( dbus_error_is_set(&error) )

    {

    printf("Error connecting to the daemon bus: %s",error.message);
	printf("DbusError init name = %s, message = %s\n ",error.name,error.message);

    dbus_error_free(&error);

    return 1;

    }

    dbus_bool_t ret = dbus_bus_name_has_owner(connection,name,&error);

    if ( dbus_error_is_set(&error) )

    {

    dbus_error_free(&error);

    printf("DBus Error: %s\n",error.message);

    return 1;

    }

    if ( ret == FALSE )

    {

    printf("Bus name %s doesn't have an owner, reserving it...\n",name);

    int request_name_reply = dbus_bus_request_name( connection,name, DBUS_NAME_FLAG_DO_NOT_QUEUE,&error);

    if ( dbus_error_is_set(&error) ){

    dbus_error_free(&error);

    printf("Error requesting a bus name: %s\n",error.message);

    return 1;

    }

     

    if ( request_name_reply == DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER )

    {

    printf("Bus name %s Successfully reserved!\n",name);

    return 0;

    }

    else

    {

    printf("Failed to reserve name %s\n",name);

    return 1;

    }

    }

    else

    /*

    if ret of method dbus_bus_name_has_owner is TRUE, then this is useful for

    detecting if your application is already running and had reserved a bus name

    unless somebody stole this name from you, so better to choose a correct bus

    name

    */

    {

    printf("%s is already reserved\n", name);

    return 1;

    }

    return 0;

    }
