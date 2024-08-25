% Example call: unethical(stevey).

% sumsum, a competitor of appy 
competitor(sumsum, appy).
competitor(appy, sumsum). 

% sumsum developed galactica-s3 
developed(sumsum, galactica-s3).

% galactica-s3 is a smartphone technology 
smartphone_technology(galactica-s3). 

% galactica-s3 was stolen by stevey 
stolen(stevey, galactica-s3). 

% stevey is a boss of appy 
boss(stevey, appy). 

% unethical for a boss to steal business from rival companies 
unethical(A) :- 
    boss(A, D), 
    business(B), 
    developed(C, B), 
    rival(C, D), 
    stolen(A, B).  

% a competitor is a rival 
rival(A, B) :- 
    competitor(A, B). 

% smartphone technology is a business 
business(A) :- 
    smartphone_technology(A).
