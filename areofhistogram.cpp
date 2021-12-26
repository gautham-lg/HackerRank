#include <iostream>
using namespace std;
#include <stack>
#include<vector>


vector<int> v1;
vector<int> v2;
vector<int>width;
vector<int>area;
int maxval = -1;
vector<int>r;
vector<int>l;

stack< pair<int,int> > sr;
stack< pair<int,int> > sl;


void nsr(int* arr,int size){
	
for(int i=size-1;i>=0;i--){
	if(i==size-1){
		v1.push_back(-1);
		r.push_back(size);
		
	}
	else{
		
		if(sr.top().first < arr[i]){
			v1.push_back(sr.top().first);
			r.push_back(sr.top().second);
		}else{
			while(sr.top().first > arr[i]){
				sr.pop();
				if(sr.empty()){
					break;
				}
			}
			if(sr.empty()){
				v1.push_back(-1);
				r.push_back(size);	
			} else{
				v1.push_back(sr.top().first);
				r.push_back(sr.top().second);	
			}
		}
		
	}
	sr.push(make_pair(arr[i],i));
}

}

void nsl(int* arr,int size){
	for(int i = 0;i<size;i++){
	if(i==0){
		v2.push_back(-1);
		l.push_back(-1);
		
	}
	else{
		
		if(sl.top().first <= arr[i]){
			v2.push_back(sl.top().first);
			l.push_back(sl.top().second);
		}else{
			while(sl.top().first > arr[i]){
				sl.pop();
				if(sl.empty()){
					break;
				}
			}
			if(sl.empty()){
				v2.push_back(-1);
				l.push_back(-1);	
			} else{
				v2.push_back(sl.top().first);
				l.push_back(sl.top().second);	
			}
		}
		
	}
	sl.push(make_pair(arr[i],i));
}
}

int main(int argc, char** argv){
//declare the input for the histogram
int arr[6] = {2,1,5,6,2,3};
int size = sizeof(arr)/sizeof(arr[0]);

nsr(arr,size);
nsl(arr,size);


for(int i = 0; i < v2.size();i++){	
	width.push_back((r[size-i-1] - l[i] - 1));
}

for(int i = 0; i < size;i++){
	area.push_back(width[i]*arr[i]);
}

for(int i = 0; i < size;i++){
	if(area[i] > maxval){
		maxval = area[i];
	}	
}

cout << "Maximum area of histogram is - " << maxval;


return 0;
}

