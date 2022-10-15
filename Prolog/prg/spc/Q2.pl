occupation(joe,oral_surgeon).
occupation(sam,patent_laywer).
occupation(bill,trial_laywer).
occupation(cindy,investment_banker).
occupation(joan,civil_laywer).
occupation(len,plastic_surgeon).
occupation(lance,heart_surgeon).
occupation(frank,brain_surgeon).
occupation(charlie,plastic_surgeon).
occupation(lisa,oral_surgeon).

address(joe,houston).
address(sam,pittsburgh).
address(bill,dallas).
address(cindy,omaha).
address(joan,chicago).
address(len,college_station).
address(lance,los_angeles).
address(frank,dallas).
address(charlie,houston).
address(lisa,san_antonio).

salary(joe,50000).
salary(sam,150000).
salary(bill,200000).
salary(cindy,140000).
salary(joan,80000).
salary(len,70000).
salary(lance,650000).
salary(frank,85000).
salary(charlie,120000).
salary(lisa,190000).

surgeon(oral_surgeon).
surgeon(plastic_surgeon).
surgeon(heart_surgeon).
surgeon(brain_surgeon).

city(houston,texas).
city(pittsburgh,pennsylvania).
city(dallas,texas).
city(omaha,nebraska).
city(chicago,lllinois).
city(college_station,texas).
city(los_angeles,california).
city(san_antonio,texas).

relation(Name):-
    occupation(Name,X),
    surgeon(X),
    address(Name,Y),
    city(Y,texas),
    salary(Name,Z),
    Z>100000.
