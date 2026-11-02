#include <stdio.h>
#include <stdbool.h>

int main(){
	int stream[] = {7,0,2,0,3};
	int page_faults = 0;
	int frames[] = {-1,-1,-1};
	int capacity = 3;
	int insertion = 0;
	int i = 0, j = 0;
	
	int total_pages = sizeof(stream)/sizeof(stream[0]);
	for(i=0; i<total_pages; i++){
		int current_page = stream[i];
		bool is_hit = false;
		for(j=0; j<capacity; j++){
			if(current_page == frames[j]){
				is_hit = true;
				break;
			}
		}
	
		if(!is_hit){
			frames[insertion] = current_page;
			insertion = (insertion + 1)%capacity;
			page_faults ++;;
			printf("Page %d -> MISS (fault)\n", current_page);
		}
		else{
			printf("Page %d -> HIT\n", current_page);
		}
	}
	printf("\n Total page faults : %d\n", page_faults);
	return 0;
}

	
			

