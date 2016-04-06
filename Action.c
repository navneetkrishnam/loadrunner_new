Action()
{

	lr_start_transaction("Launch");

	web_url("index.htm", 
		"URL=http://{Base_URL}/WebTours/index.htm", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Launch",LR_AUTO);

	lr_think_time(15);

	lr_start_transaction("login");:

	web_submit_data("login.pl", 
		"Action=http://{Base_URL}/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://{Base_URL}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=118170.865613609zAHitVDpQDztHAptiDt", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=64", ENDITEM, 
		"Name=login.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_start_transaction("Flight booking");

	/* Itinerary */	                   

	web_url("Itinerary Button", 
		"URL=http://{Base_URL}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Base_URL}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	/* click Flight Booking */
	
	web_reg_save_param("DepartDate","LB=name=\"departDate\" value=\"","RB=\"",LAST);
	web_reg_save_param("ReturnDate","LB=name=\"returnDate\" value=\"","RB=\"",LAST);
	
	//name="departDate" value="03/29/2016"   name="returnDate" value="03/30/2016"
	

	web_url("Search Flights Button", 
		"URL=http://{Base_URL}/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Base_URL}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	//name="outboundFlight" value="120;385;03/29/2016"
	
	web_reg_save_param("OBF","LB=name=\"outboundFlight\" value=\"","RB=\"",LAST);
		
	lr_think_time(23);

	web_submit_data("reservations.pl", 
		"Action=http://{Base_URL}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Base_URL}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={FromFlight}", ENDITEM, 
		"Name=departDate", "Value={DepartDate}", ENDITEM, 
		"Name=arrive", "Value={ToFlight}", ENDITEM, 
		"Name=returnDate", "Value={ReturnDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=52", ENDITEM, 
		"Name=findFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_think_time(20);

	web_submit_data("reservations.pl_2", 
		"Action=http://{Base_URL}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Base_URL}/cgi-bin/reservations.pl", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={OBF}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=reserveFlights.x", "Value=40", ENDITEM, 
		"Name=reserveFlights.y", "Value=10", ENDITEM, 
		LAST);

	lr_think_time(35);

	web_submit_data("reservations.pl_3", 
		"Action=http://{Base_URL}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Base_URL}/cgi-bin/reservations.pl", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=outboundFlight", "Value={OBF}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=56", ENDITEM, 
		"Name=buyFlights.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("Flight booking",LR_AUTO);

	lr_think_time(74);

	lr_start_transaction("Sign off");

	web_url("SignOff Button", 
		"URL=http://{Base_URL}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Base_URL}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Sign off",LR_AUTO);

	return 0;
}