M=readmatrix('C:\Users\acer\Desktop\NaturalSelection5\NaturalSelection\Plot.csv');
x= M(:,1);
y=M(:,2);
z=M(:,3);
b=M(:,4);

l=length(x);
X= [0:(l-1)]';

f=fit(X,x/2000,'poly5');
plot(f,X,x/2000,'b.');
title("Size,Speed and Sense Mutation");
hold on;

h=fit(X,z/300,'poly5');
plot(h,X,z/300,'r.');
hold on;

g=fit(X,y/200,'poly5');
plot(g,X,y/200,'g.');




legend('Size','Speed','Sense');
xlabel("Time steps")
ylabel("Trait value")
hold off;

figure;
k = fit(X,b,'poly5');
plot(k,X,b,'b.');
title('Population')
legend('No of animals')
xlabel("Time steps")
ylabel("No of Animals")

