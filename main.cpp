#include <iostream>
#include <string>

typedef struct element_t{
	std::string name = "";
	int index = 0;
	element_t* next;
}element;

typedef struct queue_t{
	element_t* head = nullptr;
}queue;

queue_t* init_queue();
void add_element(queue_t* queue, std::string name);
void print_queue(queue_t* queue);
void forward_queue(queue_t* queue);
void batch_forward(queue_t* queue, int factor);

int main(){
	queue_t* queue1 = init_queue();
	add_element(queue1, "Early Bird");
	add_element(queue1, "Worm");
	print_queue(queue1);
	forward_queue(queue1);
	add_element(queue1, "Slowpoke");
	add_element(queue1, "Apathetic");
	print_queue(queue1);
	forward_queue(queue1);
	add_element(queue1, "New Queuer");
	add_element(queue1, "Very New Queuer");
	add_element(queue1, "Bored Queuer");
	add_element(queue1, "Very Bored Queuer");
	print_queue(queue1);
	batch_forward(queue1, 2);
	print_queue(queue1);
	return 0;
}

queue_t* init_queue(){
	queue_t* new_queue = new queue_t;
	element_t* head = new element_t;
	head->name= "=HEADGUARD=";
	head->index = 0;
	head->next = nullptr;
	new_queue->head = head;
	std::cout << "New queue initalised...\n";
	return new_queue;
}

void add_element(queue_t* queue, std::string name){
	element_t* cur_el = queue->head;
	int index = 1;
	if(cur_el == NULL || cur_el == nullptr){
		return;
	}
	if(cur_el != NULL || cur_el != nullptr){
		while(cur_el->next != nullptr){
			cur_el = cur_el->next;
			index += 1;
		}
		std::cout << "Adding : " << name << " to queue...\n";
		element_t* new_el = new element_t;
		new_el->name = name;
		new_el->index = index;
		new_el->next = nullptr;
		cur_el->next = new_el;
	}
	return;
}

void print_queue(queue_t* queue){
	std::cout << "Printing Queue...\n";
	element_t* cur_el = queue->head;
	if(cur_el == nullptr || cur_el == NULL){
		return;
	}
	std::cout << "[" <<  cur_el->index << "] : " << cur_el->name << std::endl;
	while(cur_el->next != NULL || cur_el->next != nullptr){
		cur_el = cur_el->next;
		std::cout << "[" <<  cur_el->index << "] : " << cur_el->name << std::endl;
	}
	return;
}

void forward_queue(queue_t* queue){
	std::cout << "Forwarding queue...\n";
	element_t* cur_el = queue->head;
	element_t* temp_el;
	if(cur_el->next == NULL || cur_el->next == nullptr){
		std::cout << "Queue Empty...\n";
	}else{
		temp_el = cur_el;
		cur_el = cur_el->next;
		temp_el->next = cur_el->next;
		queue->head = temp_el;
		delete cur_el;
	}
}

void batch_forward(queue_t* queue, int factor){
	std::cout << "Batch forward of factor : " << factor << std::endl;
	for(int i = 0; i < factor; i++){
		forward_queue(queue);
	}
}
