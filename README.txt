============================================================

The POSTIVO is the web service, which offers sending letters and
faxes. To correctly use application, You must add your
account to API(https://postivo.pl/apiAccess.php).

============================================================
Added function from the API
============================================================
"dispatch" - Works but currently takes only 1 file 
             and 1 recipient.  
"getDispatchStatus" - Works.
"getBalance" - Works.
"getPrice" - Works.

! NOTICE !
Functions do not supported the additional settings. Support 
the additional settings will be added in the near future.
============================================================
Install
============================================================
To compile the POSTIVO,a terminal must be opened in super
user. First step after run a console in super user mode, is 
run the script called "install.sh", which copies 2 libraries 
to "/lib64". When files will be copied, compilation will start.

Example:
cd /home/user/Documents/postivo/
su
sh install.sh

! ATTENTION !
Currently only 64 bit system is supported.
Application was tested on "openSuse 15" and "SLES 12 SP1".
=============================================================
Usage
=============================================================
To run application, write in console "./postivo".
An help message will be displayed, which explains everything
options.

! Arguments !
"-d -dispatch" - create a dispatch
"-gd -gD -getDispatch" - display selected a dispatch
"-gb -gB -getBalance"  - gets from server the basic information
                         about the user
"-gp -gP -getprice"    - receives the price and information
                         about the alleged parcel
==============================================================
