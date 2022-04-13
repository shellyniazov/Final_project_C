#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// יצירת תלמיד עם תכונות
struct student { 
	int id;
	char name[100];
    char lastName[100];
    char adress[100];
	char phone[100];
    float age;
	float average;
    char dateStudies[100];
    struct student *next; 
}*head;


struct Prova
{
 char nome[16];
 int id;
 	char name[100];
    char lastName[100];
    char adress[100];
	char phone[100];
    float age;
	float average;
    char dateStudies[100];
    struct student *next;
};


struct student *current = NULL;
struct student *prev = NULL;




// הפעלת פונקציות
void Insert(int id, char* name, char* lastName, char* adress, char* phone, float age, float average, char* dateStudies);
void UpdateAvg(int id);
void RemoveStudent(int id);
void SearchStudent(int id);
void DisplayAll();
void DeleteAll();
float Average();
void maxScore();
void Fail();
void writeToFile();
void copyFiletoList();
void insert();
void ReadFromFile();
void add(int id, char* name, char* lastName, char* adress, char* phone, float age, float average, char* dateStudies);



// פונקציה ראשית
int main ()
{
    // משתנים
    FILE *fp;
    struct student* head = NULL;
    int option;
    int id;
	char name[100];
    char lastName[100];
    char adress[100];
	char phone[100];
    float age;
	float average;
    char dateStudies[30];
   


    printf("\n ------------- Students Program --------------\n\n\n");
   

    do
    {
                                                          // הדפסת תפריט
    printf("\n                Main Menu\n");
    printf("        ---------------------------\n");
    printf("         0. Read content from file.\n");
    printf("         1. Adding a new student.\n");
    printf("         2. Average update for a student.\n");
    printf("         3. Student presentation.\n");
    printf("         4. Print all students.\n");
    printf("         5. Deleting a student.\n");
    printf("         6. Delete all students.\n");
    printf("         7. View statistics.\n");
    printf("         8. Exit.\n");
    printf("        ---------------------------\n");
    
    printf("         Please enter an option: ");
    scanf("%d", &option);
    printf("\n");


    switch(option){


    case 0: // read from file
         ReadFromFile();
 
    break;


    case 1: // add to list
        printf("\n");
        printf("\tEnter your id: ");
        scanf("%d", &id);
        printf("\tEnter your name: ");
        scanf("%s", name);
        printf("\tEnter your last name: ");
        scanf("%s", lastName);
        printf("\tEnter your adress: ");
        scanf("%s", adress);
        printf("\tEnter your phone number: ");
        scanf("%s", phone);
        printf("\tEnter your age: ");
        scanf("%f", &age);
        printf("\tEnter your average: ");
        scanf("%f", &average);
        printf("\tEnter the date of start of school: ");
        scanf("%s", dateStudies);
       
        Insert(id,name,lastName,adress,phone,age,average,dateStudies);
    break;


    case 2: // update average by id 
       printf("\n");
       printf("\tEnter ID to update average: ");
       scanf("%d", &id);
       UpdateAvg(id);
    break;


    case 3: // view student by id
       printf("\n");
       printf("\n\tEnter your ID to view a student: ");
       scanf("%d", &id);
       printf("\n\tStudent details by id: \n");
       SearchStudent(id);
    break;


    case 4: // view all
       DisplayAll();
    break;


    case 5: // remove student by id
       printf("\tEnter ID to remove a student: ");
       scanf("%d", &id);
       RemoveStudent(id);
    break;


    case 6: // remove all
       DeleteAll();
    break;
        

    case 7: // view statistics
       printf("\n\tAverage of all students: ");
       printf("%f", Average(average));
       printf("\n\tThe students whose highest score is: ");
       maxScore();
       printf("\n\tThe students who failed are: \n");
       Fail();
    break;
        

    case 8: // exit + write to file
        
        printf("\n\tGoodbye!!!\n\n\n");
        writeToFile();
    break;


    default: 
       printf("\n\tinvalid input\n\n\n");
       break;
    }

    } while(option != 8);
}





// הוספת תלמידים לרשימה
void Insert(int id, char* name, char* lastName, char* adress, char* phone, float age, float average, char* dateStudies)
{
    struct student * student = (struct student *) malloc(sizeof(struct student));

	student->id = id;
	strcpy(student->name, name);
    strcpy(student->lastName, lastName);
    strcpy(student->adress, adress);
	strcpy(student->phone, phone);
	student->age = age;
    student->average = average;
    strcpy(student->dateStudies, dateStudies);
	student->next = NULL;
   

    if(head == NULL)
    {
        head = student;
    }
    else
    {
        student->next = head; 
        head = student;          

        printf("\n\tDATA INSERTED SUCCESSFULLY\n\n");
    }
}





// עדכון ממוצע של תלמיד אחרי מציאתו ע"י ת.ז
void UpdateAvg(int id)
{
struct student * temp = head;

while(temp != NULL) 
{
  if(temp -> id == id)
  {
   printf("\n\tEnter the new average to update: ");
   scanf("%f", &temp->average);
   printf("\n\tThe average was updated! ");
   return;
  }
   temp = temp-> next; 
}
    printf("\tThe student with the required ID %d is not found..\n", id);
}






// הצגת פרטי תלמיד לאחר חיפושו ע"י ת.ז
void SearchStudent(int id)
{
    struct student * temp = head;

	while(temp!=NULL){
		if(temp->id == id)
        {
 	        printf("\tId: %d\n", temp->id); 
            printf("\tName: %s\n", temp->name); 
            printf("\tLast Name: %s\n", temp->lastName); 
            printf("\tAdress: %s\n", temp->adress); 
            printf("\tPhone: %s\n", temp->phone); 
            printf("\tAge: %f\n", temp->age); 
            printf("\tAvrage: %f\n", temp->average); 
            printf("\tDate of start of school: %s\n", temp->dateStudies); 
			return;
		}
		temp = temp->next;
	}
	printf("\tThe student you tried to find is not on the list!\n");
}








// הצגת רשימת תלמידים
void DisplayAll()
{
    struct student *temp;

    if(head == NULL)
    {
        printf("\n\tList is empty.\n\n\n");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("\n\n----------------Stusent Details------------------\n\n"); 
           	printf("\tId: %d\n", temp->id); 
            printf("\tName: %s\n", temp->name); 
            printf("\tLast Name: %s\n", temp->lastName); 
            printf("\tAdress: %s\n", temp->adress); 
            printf("\tPhone: %s\n", temp->phone); 
            printf("\tAge: %f\n", temp->age); 
            printf("\tAvrage: %f\n", temp->average); 
            printf("\tDate of start of school: %s\n", temp->dateStudies); 
            printf("\n\n--------------------------------------------------\n\n"); 
            temp = temp->next;                 
        }
    }
}






// מחיקת סטודנט לפי ת.ז
void RemoveStudent(int id) {
   int pos = 0;
   
   if(head==NULL) 
   {
      printf("\tLinked List not initialized");
      return;
   } 
    
   if(head->id == id)
    {
      if(head->next != NULL) 
      {
         head = head->next;
         return;
      } else {
         head = NULL;
         printf("\tList is empty now");
         return;
      }
   } 
   else if(head->id != id && head->next == NULL) 
   {
      printf("%d Not found in the list\n", id);
      return;
   }

   current = head;
   
   while(current->next != NULL && current->id != id) 
   {
      prev = current;
      current = current->next;
   }        

   if(current->id == id)
    {
      prev->next = prev->next->next;
      free(current); // שחרור הזכרון הרלוונטי
    } 
   else
      printf("%d Not found in the list.", id);
}







// מחיקת רשימת כל הסטודנטים
void DeleteAll()
{
    struct student *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;

        free(temp); // שחרור הזכרון
    }

    printf("\t--SUCCESSFULLY DELETED ALL STUDENTS OF THE LIST--\n");
}




/////////////////////////////////////////////////// הצגת סטטיסטיקה



// חישוב ממוצע כל הציונים של התלמידים
float Average() 
{ 
    struct student * temp = head;

    if (!head) 
        return -1; 
  
    int count = 0; 
    int sum = 0; 
    float avg = 0.0; 
  
    struct student* current = head; 
    while (current != NULL) 
    { 
        count++; 
        sum += current->average; 
        current = current->next; 
    } 
  
    // calculate average 
    avg = (double)sum / count; 
  
    return avg; 
}







void maxScore() 
{ 
    struct student * current = head;  
    struct student * prev = head;  

    int max = 0; 

    while (current != NULL) 
    { 
        if (max < current->average)
        { 
            max = current->average;
        }
        current = current->next;

   
    } 

     
    while (prev != NULL) 
    { 
        if (prev->average == max)
        { 
            printf("\n\t%s",prev->name); 
        }
        prev = prev->next;
    } 
} 
   





// תלמידים שנכשלו - הציון שלהם מתחת ל60
void Fail() {  
    struct student * temp = head;

    while(temp != NULL) 
    {
     if(temp->average < 60)
    {              
     printf("\t%s", temp->name);  
    }
     temp = temp->next; 
    }  
}  



////////////////////////////////////////////////////////////////



// כתיבת נתוני תלמידים לתוך קובץ
void writeToFile()
{
    FILE * fptr;
    fptr = fopen("proC.txt", "w");
    struct student * temp = head;

    if(fptr==NULL)
    {
        printf("Error\n");
    }

    else
    {
        while(temp!= NULL)
        {
            fprintf(fptr, "\nID: %d\nName: %s\nLast-Name: %s\nAddress: %s\nPhone: %s\nAge: %f\nAverage: %f\nDate of studies: %s", temp->id,
            temp->name,temp->lastName,temp->adress,temp->phone,temp->age,temp->average, temp->dateStudies);
            printf("\n");
            temp= temp->next;
        }
    }
    fclose(fptr);
}




// קריאת נתונים מהקובץ 
void ReadFromFile(){
   FILE * fptr;
   char ch;

   fptr = fopen("proC.txt", "r"); // read mode

   if (fptr == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   printf("The contents of %s file are:\n", "proC.txt");

   while((ch = fgetc(fptr)) != EOF)
      printf("%c", ch);
   
   fclose(fptr);
}




//////////////////////////////////////////////////////////////////////////////////////////  קריאת נתונים מקובץ - והכנסתם לרשימה - היתה לי תקלה - זה נכנס פעם אחת לרשימה ונעצר


// void ReadFromFile(){
//     struct student * object = (struct student *) malloc(sizeof(struct student));
//     //  ;
//     // struct student * student = (struct student *) malloc(sizeof(struct student));
//     FILE * fptr;
//     char ch;

//     fptr = fopen("output", "rb"); // read mode

//     if (fptr == NULL)
//     {
//         perror("Error while opening the file.\n");
//         exit(EXIT_FAILURE);
//     }

//     fread(object, sizeof(struct student), 10, fptr);
//     head = object;
    

//     object = object->next; 
    
//     fclose(fptr);
// }

