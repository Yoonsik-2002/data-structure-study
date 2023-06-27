## 🧾 구조체
구조체를 공부하기 전에, 자료구조에 대한 개념을 간단히 짚고 넘어가 보도록 하겠다. 
### 자료구조란?
프로그램이란 데이터를 표현(저장)하고, 그렇게 표현된 데이터를 처리하는 것이다. 때문에 일반적인 프로그램은 논리적으로 따져보면 크게 데이터를 표현하는 **자료구조**와 표현된 데이터를 처리하는 **알고리즘**으로 나눌 수 있다. 

위에서 말했듯이, 자료구조란 데이터의 표현을 담당하는 개념이다. <br>이때, 데이터의 표현은 데이터의 저장이라는 개념도 내포한다.
이러한 이유로 **넓은 의미에서 프로그램에 사용되는 일반 변수, 구조체, 배열 또한 데이터의 표현(저장)과 관련된 개념이므로, 자료구조에 속한다.**

### 구조체(struct)란?
구조체란 일상의 레코드 데이터를 저장하기 위해 마련된 C 프로그램의 자료구조로, 서로 연관성을 띄지만 데이터 타입이 다른(다양한) 데이터들을 묶어 하나의 새로운 자료형을 만들어 준다. 
**즉, 이렇게 생성된 구조체는 하나의 단위로 취급되는 자료들의 집합이라 할 수 있다.**
<br><br>

## 구조체의 선언
- #### 기본적인 방식의 구조체 선언 <br>
  기본적으로 구조체는 **`struct`** 키워드를 통해 선언이 가능하며, 이러한 방식으로 선언된 구조체의 자료형은 **`struct 구조체 태그 이름`** 형태를 띄게 된다.    
  struct 키워드만을 이용한 기본적인 방식의 구조체 선언은 아래와 같다. 
  
  ```c 
  // 학생 데이터를 저장하는 구조체의 선언
  struct student {
    int stdID;
    char name[20];
    float score;
  };
  ```
  *서로 연관성이 있지만, 자료형이 다른(다양한) 데이터 **`stdID`**, **`name[20]`**, **`score`** 는 **`struct student`** 라는 새로운 하나의 자료형으로 묶이게 된다.*
  
- #### 형 정의문(**`typedef`**)를 이용한 구조체 선언 <br>
  형 정의문 **`typedef` (type definition)** 는 자료형을 정의해주는 역할을 한다.    
  이 형 정의문을 이용하여 구조체를 선언할 경우, 구조체 별칭(**`typedef`** 를 통해 정의된 자료형)을 사용하기 때문에 **`struct 구조체 태그 이름`** 형태의 자료형을 사용하지 않게 된다.   
  따라서 main()에서 구조체 타입의 구조체 변수나 구조체 배열을 선언할 때 **`struct`** 키워드를 써줄 필요가 없다. 
  
  ```c
  // 형 정의문(typedef)를 이용한 학생 데이터를 저장하는 구조체의 선언
  typedef struct {
    int stdID;
    char name[20];
    float score;
  }stdData;
  ```
  서로 연관성이 있지만, 자료형이 다른(다양한) 데이터 **`stdID`**, **`name[20]`**, **`score`** 는 형 정의문을 통해 새롭게 정의된 자료형 **`stdData`** 라는 새로운 하나의 자료형으로 묶이게 된다.
  ```c
  // main()에서 해당 구조체 타입의 구조체 변수 또는 구조체 배열 선언 시, typedef 로 새롭게 정의한 자료형을 이용하여 선언한다. 
  ...
  main()
  { 
      stdData onep, exmember[30];
      ...
  }
  ```
  형 정의문을 이용하여 선언된 구조체의 경우, 위 코드와 같이 main()에서 해당 구조체 타입의 구조체 변수나 구조체 배열 선언 시, (**`struct 구조체 태그 이름`** 이 아닌) 새롭게 정의된 구조체 별칭을 자료형으로 사용한다. 즉, 자료형에 **`struct`** 태그를 붙이지 않는다.
  <br><br>
  
## 구조체 변수
먼저 예시로 사용할 인적사항 구조체를 만들어 보겠다.
```c
typedef struct {
  int ID;
  char name[20];
  int age;
  float height;
  float weight;
}personal_info;
```

### 구조체 변수의 선언과 초기화
- #### 멤버연산자 `.`를 이용하여 구조체 변수 안의 멤버에 접근하기 
  ```c
  main()
  {
    personal_info my_info;
    
    my_info.ID = 2022123423
    strcpy(my_info.name, "조윤식");
    my_info.age = 22;
    my_info.height = 172.6;
    my_info.weight = 63.4;
  }
  ```
  구조체 변수 `my_info`를 선언하고 , 멤버연산자 `.`를 이용하여 해당 구조체 변수안에 존재하는 멤버(ID, name, age, height, weight)에 값을 저장하였다.
  
  ```c
  printf("Information of %s\n ID : %d \n Name : %s \n Age : %d \n Height : %.1f \n Weight : %.1f\n", my_info.ID, 
  my_info.name, my_info.age, my_info.height, my_info.weight);
  ```
  구조체 변수안의 멤버에 저장된 값을 출력할 때에도 구조체 멤버에 접근(값 저장)할 때와 같이 `구조체 변수.멤버` 형식을 이용한다.
  <br><br>
  
## 구조체 배열
다수의 `int`형 변수를 선언하기 위해 우리는 배열을 사용한다. 그럼, 다수의 구조체 변수를 선언하기 위해서는 무엇을 사용하면 되는가? 바로 구조체 배열을 사용하면 된다.
구조체 배열에 대해 전화번호부를 예시로 들어 설명해 보겠다.

우리는 보통 지인의 전화번호를 저장할 때 핸트폰의 연락처를 저장한다. 연락처는 간단히 전화번호와 해당 번호를 가진 사람의 이름으로 구성되어 있다. 
민수의 연락처를 c언어 구조체 변수로 표현해 보겠다. 

```c
...
  typedef struct {
    char name[20];
    int num;
  }contact_number;
  
  int main() {
    contact_number minsu;
```

이때 우리는 핸드폰에 한 사람의 연락처만 저장하지 않는다. 우리는 여러 지인의 연락처(이름과 전화번호로 구성된)를 전화번호부에 저장한다. 
이렇게 여러 연락처를 저장하는 전화번호부를 c언어 구조체 배열로 표현해 보겠다.

```c
...
  typedef struct {
    char name[20];
    int num;
  }contact_number;
  
  int main() {
    ... 
    contact_number minsu, number_list[3];
 ```
 위 코드를 보면 전화번호부 역할을 하는 구조체 배열 `number_list`가 선언된 것을 볼 수 있다. 구조체 배열의 선언도 일반 배열의 선언과 크게 다른것이 없다는 것을 알 수 있다.
 
 ```c
 int main()
{
	contact_number phone_book[30];
	int i, pnum;
	
	printf("Input number of person : ");
	scanf("%d\n", &pnum);
	
	for (i = 0; i < pnum; i++) {
		printf("Input person name and number : ");
		scanf("%s %d\n", phone_book[i].name, &phone_book[i].num);
	}
	
	printf("--Your contact number list--");
	puts("");
	for (i = 0; i < pnum; i++) {
		printf("Name : %s -- Phone number : %d\n", phone_book[i].name, phone_book[i].num);
	}
	puts("");
	printf("-----------------------------\n");
}
``` 
<br><br>

## 구조체 포인터 변수
구조체 포인터 변수의 선언 방법은 일반 포인터 변수의 선언 방법과 크게 다르지 않다. 
```c
// 점의 x, y 좌표값을 저장하는 구조체 spot
typedef struct {
  int xpos;
  int ypos;
}spot;
```
```c
// 구조체 포인터 변수의 선언과 초기화
spot pos1 = {10, 17};
spot * pptr = &pos1; // spot 타입의 구조체 포인터 변수 pptr을 선언하고, 구조체 변수 pos1을 가리키도록 선언과 동시에 초기화 하였다. 
```
위 코드에서 보았듯이, 구조체 포인터 변수의 선언도 **`자료형 * 구조체 포인터 변수 이름;`** 형태를 띈다. 

### 구조체 포인터 변수로 구조체 변수에 접근하기
```c
(*pptr).xpos = 20;
(*pptr).ypos = 27;
```
다음 코드를 보면, 먼저 **`spot * pptr = &pos1;`** 로 인해, 구조체 포인터 변수 **`pptr`** 은 구조체 변수 **`pos1`** 을 가리키고 있는 상태이다.<br>
즉, **`*pptr == pos1`** 가 성립하게 되는 것이다. 
이러한 상태에서 pos1의 어떤 멤버(xpos, ypos)를 참조할지 **`.`** 연산자를 사용하여 선택하였다. 

결국 해당 코드는 구조체 변수 **`pos1`** 에 접근하기 위해 **`*`** 연산자를 사용하였고, **`pos1`** 에 접근 후, 해당 구조체 변수의 어느 멤버를 선택할지 지정하기 위해 **`.`** 연산자를 사용 한 것을 알 수 있다. 
```c
(*pptr).ypos = 27; // * 연산자는 pos1 에 접근을 위해, . 연산자는 접근한 구조체 변수의 어느 멤버를 선택할지 지정하기 위해 사용.
```
이 두 연산자(**`*`**, **`.`**)의 역할을 100% 같은 의미로 대신할 수 있는 연산이 있다. 바로 **`->`** 연산자 이다.
**`->`** 연산자를 이용하여 위 코드를 대신해보면 다음과 같다. 
```c
pptr->xpos = 20; // pptr이 가리키는 구조체 변수의 멤버 xpos의 값을 20으로 지정
pptr->ypos = 27; // pptr이 가리키는 구조체 변수의 멤버 ypos의 값을 27로 지정
```
**`->`** 연산자의 사용은 처음에는 생소할 수 있지만 위 코드의 주석처럼 이해해보면 금방 익숙해진다. 

### 구조체 포인터 변수를 멤버로 가지는 구조체
위에서 설명한 내용 (구조체 포인터 변수, **`->`**)을 예시코드를 통해 어떤식으로 쓰이는지 설명해 보려고 한다. 

```c
// ex 1) 구조체 포인터 변수를 활용한 원의 중심점, 반지름을 출력해주는 프로그램

#include <stdio.h>

typedef struct {
  int xpos;
  int ypos;
}center_coor;

typedef struct {
  center_coor * pptr; // center_coor 타입의 구조체 포인터 변수 pptr
  double radius;
}circle;
```
```c
int main()
{
  center_coor cen = {10, 18}; // 원의 중심점의 좌표(x축, y축)값을 저장하는 구조체 변수 pos1 선언 및 초기화
  double rad = 5.5;
```
```c
  circle ring = {&cen, rad}
```
circle 타입의 구조체 변수 ring 선언, 첫 번째 멤버인 center_coor 타입의 구조체 포인터 변수 pptr 에 위에서 먼저 선언된 center_coor 타입의 구조체 변수 cen의 주소값이 저장된다.<br> 
즉, 구조체 포인터 변수 pptr이 구조체 포인터 변수 cen을 가리키고 있는 상태가 된다. **`center_coor * pptr = &cen`**
```c
  // 원의 반지름과 중심점 출력
  printf("원의 반지름 : %g\n", rign.radius);
```
```c
  printf("원의 중심점 : [%d, %d]\n", (ring.pptr)->xpos, (ring.pptr)->ypos);
}
```
circle 타입의 구조체 변수 ring의 center_coor 타입의 구조체 포인터 변수 pptr이 가리키고 있는 center_coor 타입의 구조체 변수 cen의 멤버 xpos, ypos 값을 출력한다.<br>
더 풀어서 설명하면 **`(ring.pptr)->xpos`** 에서 **`.`** 연산자는 ring 이라는 구조체 변수의 멤버인 pptr과 radius 중 무엇을 선택할지 지정해주는 역할을 하고 **`->`** 연산자는 **`*`** 연산자와 **`.`** 연산자의 역할을 동시에 수행하여, 구조체 포인터 변수가 가리키고 있는(**`*`** 연산자의 역할) 구조체 변수 cen 의 멤버인 xpos와 ypos중 무엇을 선택할지(**`.`** 연산자의 역할) 지정해주는 역할을 한다. 
<br><br>

## 구조체 변수의 주소값과 구조체 변수의 첫 번째 멤버의 주소값
구조체 변수의 주소값은 구조체 변수의 첫 번째 멤버의 주소값과 동일하다. 
해당 내용은 다음 코드를 통해서 확인해 보도록 하겠다. 

```c
#include <stdio.h>

typedef struct {
  int ID;
  char Pass_Word[20];
}member;

int main()
{
  member example_member = {20211059, "asdfe1203"};
  member * pptr = &example_member;
	
  printf("구조체 변수 example_member의 주소값 : %p\n", pptr); // 구조체 포인터 변수 pptr이 가리키고 있는 구조체 변수 example_member의 주소값
  printf("구조체 변수 example_member의 첫 번째  멤버의 주소값 : %p\n", &pptr->ID); // 구조체 포인터 변수 pptr이 가리키고 있는 구조체 변수 example_member의 첫 번째 멤버 ID의 주소값
}
```

일단, 회원의 ID와 password를 저장하는 구조체 **`member`** 를 생성하였고, **`member`** 타입의 구조체 변수 **`example_member`** 를 선언과 동시에 초기화 해주었다.
그리고, 구조체 포인터 변수 **`pptr`** 을 선언하여, 구조체 변수 **`example_member`** 를 가리키도록 하였다. (example_member의 주소값을 구조체 포인터 변수 pptr에 저장하였다.)
<br><br>
마지막으로 pptr에 저장되어 있는 구조체 변수 **`example_member`** 의 주소값과 **`example_member`** 의 첫 번째 멤버의 주소값을 출력하였다.<br>
해당 프로그램의 실행 결과는 다음과 같다. ~~(군대 사지방 컴퓨터는 화면 캡쳐후, 저장해서 업로드 하는것이 불가능 하므로, 그냥 내가 실행결과를 적도록 하겠다.)~~
```c
[실행결과]

구조체 변수 example_member의 주소값 : 0x7fff71349290
구조체 변수 example_member의 첫 번째  멤버의 주소값 : 0x7fff71349290
```
위 실행 결과에서 확인해 볼 수 있듯이, **구조체 변수의 주소값과 해당 구조체 변수의 첫 번째 멤버의 주소값은 동일하다 !**
<br><br>

## 함수로의 구조체 변수 전달과 반환
구조체 변수를 함수의 인자로, 해당 함수의 매개변수에 전달하거나 함수 내에서 **`return`** 문을 통해서 구조체 변수를 반환하는 경우, 발생하는 모든 현상은 **`int`** 형 변수를 인자로 전달하거나 반환하는 경우에 발생하는 현상과 완전히 동일하다.
```c
void example_func(int num) { ... };

int main() 
{
  int number = 22;
  example_func(number);
}
``` 
위의 예시 코드는 **`int`** 형 변수 **`number`** 를 **`example_func`** 함수의 인자로 전달하는 내용을 담은 코드이다. 이때, 변수 **`number`** 에 저장되어 있는 값인 22는 **`example_func`** 함수의 매개변수 **`num`** 에 복사되어 전달되게 된다.
<br><br>
구조체 변수 또한 함수의 인자로서 해당 함수의 매개변수에 전달 될 수 있다. 그리고, 전달되는 구조체 변수의 값은 매개변수에 통째로 (int형 변수가 전달되는 것과 같이) 복사되어 전달된다. 

```c
#include <stdio.h>

typedef struct {
	int xpos;
	int ypos;
}spot;

spot current_coordinate(void) {
	spot cen;
	printf("Input coordinate of spot : ");
	scanf("%d %d", &cen.xpos, &cen.ypos);
	return cen; // spot 타입의 구조체 변수 cen에 값 저장 후, 반환(return)
}

void show_coordinate(spot pos) {
	printf("[%d, %d]\n", pos.xpos, pos.ypos);
}

int main()
{
	spot cur_spot = current_coordinate(); // current_coordinate 함수 실행 후, 리턴되는 구조체 변수 cen에 저장되어 있는 값이 cur_spot에 나란히 복사되어 저장된다. 
	show_coordinate(cur_spot); // spot 타입의 구조체 변수 cur_spot가 show_coordinate 함수에 인자로 전달된다. 이때, cur_spot 에 저장되어 있는 값이 나란히 복사되어 매개변수 pos 에 저장된다. 
}
```
**`current_coordinate`** 함수가 실행되며 구조체 변수 **`cur_spot`** 에 반환된(**return**) **`spot`** 타입의 구조체 변수 **`cen`** 에 저장된 값은 나란히 복사되어 **`cur_spot`** 에 저장된다. 
<br>또, **`show_coordinate`** 함수에 인자로서 전달된 구조체 변수 **`cur_spot`** 에 저장된 값들은 나란히 복사되어 **`show_coordinate`** 함수의 매개변수 **`pos`** 에 저장된다.<br><br> 
**이렇게 함수에 인자로서의 전달과정에서, 값의 반환과정(return)에서 구조체 변수에 저장된 값들은 복사되어 전달되게 된다.**
<br><br>

### 구조체 변수의 멤버가 배열인 경우 인자의 전달과 값의 반환
위의 예시에서는 구조체의 멤버로 선언된 int 형 변수 멤버 **`xpos`, `ypos`** 의 값들이 함수에 인자로 복사되어 전달되고, 값의 반환 과정에서도 복사되어 전달 된다는 것을 나타내었다. <br>

이때, 구조체 변수의 멤버가 위 예시처럼 int 형 변수가 아닌, 배열이라면 어떤식으로 함수에 인자로 전달되고, 값의 반환과정 또한 어떤식으로 이루어질까?<br>
int 형 변수 멤버의 값이 **복사되어 함수의 인자로 전달되고, 값의 반환과정 또한 복사되어 전달** 되듯이, 구조체 변수의 멤버가 배열인 경우에도(구조체의 멤버로 선언된 배열의 경우에도), 배열이 통째로 복사되어 전달되게 된다.  

```c
#include <stdio.h>

typedef struct {
	char name[20];
	char phone_num[25];
	int age;
}person;

person read_person_info(void){
	person man;
	printf("--Input Information of person--\n");
	printf("Name : "); scanf("%s", man.name);
	printf("Phone Number : "); scanf("%s", man.phone_num);
	printf("Age : "); scanf("%d", &man.age);
	printf("-------------------------------\n");
	puts("");
	return man;
}

void show_person_info(person a){
	printf("----Information of %s----\n", a.name);
	printf("Name : %s\n", a.name);
	printf("Phone Number : %s\n", a.phone_num);
	printf("Age : %d\n", a.age);
	printf("-----------------------------\n");
}

int main()
{
	person man1 = read_person_info();
	show_person_info(man1);
}
```
위 코드를 보면 **`read_person_info`** 함수를 통해 구조체 변수 **`man`** 이 선언되고, 해당 구조체 변수의 멤버들에 값을 입력하게 된다. 이때, 구조체 변수 **`man`** 의 멤버중 **`name`** 과 **`phone_num`** 은 배열인 것을 알 수 있다.<br>

**`man`** 에 데이터가 다 입력 되고, 해당 구조체 변수가 **return** 될 때, **`man`** 의 멤버인 **`name`**, **`phone_num`** 는 배열일지라도 상관 없이 int 형 변수 형태인 **`age`** 와 같이 통째로 복사되어 멤버 대 멤버로 값이 구조체 변수 **`man1`** 에 전달된다. 

또, 구조체 변수 **`man1`** 이 **`show_person_info`** 함수에 인자로서 전달될 때도 **`man1`** 의 멤버인 **`name`** , **`phone_num`**, **`age`** 모두 복사되어 매개변수에 멤버 대 멤버로 전달된다.<br>

### 구조체 변수를 대상으로 하는 Call-by-reference
Call-by-reference 또는 Call-by-value가 무엇인지에 대한 설명은 다음 링크에서 확인해 볼 수 있다. <br>[Call-by-value 와 Call-by-reference](https://github.com/Yoonsik-2002/data-structure-study/tree/main/000_other_knowledge/000_call_by_value_and_call_by_reference)

함수를 정의할 때 구조체 포인터 변수를 매개변수로 선언하여, 해당 매개변수에 구조체 변수의 주소값이 전달되게 하는 **구조체 변수를 대상으로 하는 Call-by-reference 형태의 함수호출이 가능하다.**
<br>
다음 코드를 보고 이해해 보자. 

```c
// call-by-reference 형태의 함수 호출을 이용하여 x, y좌표값을 원점대칭 이동시키는 프로그램 
#include <stdio.h>

typedef struct {
	int xpos;
	int ypos;
}point;

void change_coordinate(point * pptr) { // 구조체 포인터 변수 형태로 선언된 매개 변수 pptr. 이를 통해 call-by-reference 형태의 함수호출이 가능해지고, 함수 내에서 함수 밖에 선언된 변수에 접근이 가능하게 된다. 
	printf("pos1의 x,y 좌표의 원점 대칭 이동 수행중 ...\n");
	pptr->xpos = (pptr->xpos) * -1; // (*pptr.xpos) * -1 과 같은 의미
	pptr->ypos = (pptr->ypos) * -1; // (*pptr.ypos) * -1 과 같은 의미
	printf("수행 완료 !\n");
	puts("");
}

void restoration(point pos1) {
	printf("좌표의 이동을 다시 원상 복구하겠습니다.\n");
	change_coordinate(&pos1);
	printf("원상 복구된 pos1의 x, y 좌표 : [%d, %d]\n", pos1.xpos, pos1.ypos);
}

int main()
{
	point pos1 = {-7, 5};
	printf("pos1의 x, y 좌표 : [%d, %d]\n", pos1.xpos, pos1.ypos);
	puts("");
	change_coordinate(&pos1);
	printf("원점 대칭이동 된 pos1의 x, y 좌표 : [%d, %d]\n", pos1.xpos, pos1.ypos);
	puts("");
	restoration(pos1);
}
```
```c
[실행결과]
pos1의 x, y 좌표 : [-7, 5]

pos1의 x,y 좌표의 원점 대칭 이동 수행중 ...
수행 완료 !

원점 대칭이동 된 pos1의 x, y 좌표 : [7, -5]

좌표의 이동을 다시 원상 복구하겠습니다
pos1의 x,y 좌표의 원점 대칭 이동 수행중 ...
수행 완료 !

원상 복구된 pos1의 x, y 좌표 : [-7, 5]
```
위 프로그램을 통해 알 수 있듯이, **구조체 포인터 변수 형태로 선언된 함수의 매개변수에 구조체 변수의 주소값을 전달하여 Call-by-reference 형태의 함수호출을 구성할 수 있다.**<br>
이 경우, 코드에서 볼 수 있듯이, **`change_coordinate`** 함수 내에서 해당 함수 밖에 선언된 구조체 변수 pos1에 접근이 가능해진다 !!!!
<br><br>

## 구조체 변수를 대상으로 하는 연산
기본 자료형 변수를 대상으로는 사칙연산, 비교연산 등 다양한 연산이 가능하다. 하지만, 구조체 변수를 대상으로는 제한된 형태의 연산만이 가능하다. 다음은 구조체 변수를 대상으로 허용되는 대표적인 연산들이다. 

- 대입연산
- 주소값 반환 목적의 **`&`** 연산
- 구조체 변수의 크기를 반환하는 **`sizeof`** 연산

```c
#include <stdio.h>

typedef struct {
	int xpos;
	int ypos;
}spot;

int main()
{
	spot pos1 = {10, 12};
	// 구조체 변수의 대입 연산 - pos1의 멤버 대 pos2의 멤버간의 복사가 진행됨 쉽게말해, pos1 의 멤버 10, 12가 복사되어 그대로 pos2의 멤버에 전달됨
	spot pos2 = pos1;
	
	printf("구조체 변수 pos1의 크기 : %ld\n", sizeof(pos1)); // 구조체 변수의 크기를 반환하는 sizeof 연산
	printf("[%d, %d]\n", pos1.xpos, pos1.ypos);
	puts("");
	printf("구조체 변수 pos2의 크기 : %ld\n", sizeof(pos2));
	printf("[%d, %d]\n", pos2.xpos, pos2.ypos);
}
```
```c
[실행결과]
구조체 변수 pos1의 크기 : 8
[10, 12]

구조체 변수 pos2의 크기 : 8
[10, 12]
```
### 구조체 변수를 대상으로 덧셈과 뺄셈과 같은 사칙연산이 불가능한 이유
구조체 변수를 대상으로 허용되는 연산이 이렇게 종류가 적다니.. 라는 생각이 들 수도 있다. 그럼 구조체 변수를 대상으로 사칙연산이 불가능한 이유는 무엇일까?<br>
**구조체 안에는 우리가 흔히 생각하는 기본 자료형 변수 뿐만 아니라, 배열, 포인터 변수, 심지어 다른 구조체의 변수도 존재할 수 있다.<br>
이러한 상태에서 구조체 변수를 대상으로 사칙연산의 결과를 정형화 하는 것은 무리가 있다.** <br><br>
그렇다면 구조체 변수를 대상으로 사칙연산을 하기 위해선 어떻게 해야 할까?<br>
정답은 함수의 정의를 통해서 사칙연산의 결과를 프로그래머가 직접 정의 해야 한다. 

다음은 점의 좌표값(x, y값)을 멤버로 하는 구조체 변수 **`pos1`** 과 **`pos2`** 를 대상으로 덧셈과 뺄셈 연산을 하는 프로그램이다. 

```c
#include <stdio.h>

typedef struct {
	int xpos;
	int ypos;
}point;

point add_point(point pos1, point pos2);
point min_point(point pos1, point pos2);

int main()
{
	point pos1 = {10, 20};
	point pos2 = {30, 40};
	
	point result;
	
	result = add_point(pos1, pos2);
	printf("add_point 의 계산 결과 : [%d, %d]\n", result.xpos, result.ypos);
	
	result = min_point(pos1, pos2);
	printf("min_point 의 계산 결과 : [%d, %d]\n", result.xpos, result.ypos);
}

point add_point(point pos1, point pos2){
	point pos = {pos1.xpos + pos2.xpos, pos1.xpos + pos2.ypos};
	return pos;
}

point min_point(point pos1, point pos2){
	point pos = {pos2.xpos - pos1.xpos, pos2.xpos - pos1.ypos};
	return pos;
}
```
<br><br>

## 중첩 구조체
구조체의 멤버로 배열이나 포인터 변수가 선언될 수 있었듯이, 구조체 변수 또한 구조체의 멤버로 선언이 가능하다. 이렇게 **구조체 안에 구조체 변수가 멤버로서 존재하는 경우를 구조체의 중첩, 즉 중첩 구조체라 한다.**

다음은 중첩 구조체를 예시로 한 프로그램이다. 
```c
typedef struct {
	int xpos;
	int ypos;
}point;

typedef struct {
	point cen; // circle 이라는 구조체에 멤버로서 선언된 point 구조체 변수 cen. 이렇게 구조체 안에 구조체 변수가 멤버로서 존재하는 경우를 구조체의 중첩이라 한다. 
	float radius;
}circle;

void show_circle_info(circle * ptr) {
	printf("[%d, %d]\n", (ptr->cen).xpos, (ptr->cen).ypos); // 구조체 포인터 변수 ptr이 가리키고 있는(*) 구조체 변수 c1의 멤버(.) cen의 멤버(.)인 xpos의 값, ypos의 값
}

int main()
{
	circle c1 = {{10, 20}, 4.5}; // 구조체 변수가 멤버로 존재할 경우, {}(중괄호)를 이용하여 구분지어 구조체 변수를 초기화 해 줄 수 있다.
	circle c2 = {30, 40, 5.5}; // 중괄호로 구분짓지 않는 경우, 순서대로 초기화가 이루어 진다. (cen.xpos = 30, cen.ypos = 40, radius = 5.5 순으로)
	
	show_circle_info(&c1);
	puts("");
	show_ciecle_info(&c2);
}
```
위 코드를 살펴보면, 먼저 circle 구조체에 point 타입의 구조체 변수 **`cen`** 이 멤버로서 선언되어 있는 것을 알 수 있다. 다음과 같이 구조체 안에 구조체 변수가 멤버로서 존재하는 경우를 구조체의 중첩이라 한다. <br>
그리고, main() 안을 보면, circle 타입의 구조체 변수 **`c1`** 과 **`c2`** 가 선언과 동시에 초기화 되는것을 볼 수 있는데, 구조체 변수가 멤버로 존재하는 중첩 구조체의 구조체 변수의 경우 다음 2가지 방법을 통해 초기화가 가능하다. 방법은 간단하다.

- #### 중괄호 **`{}`** 를 사용하여 구조체 변수 멤버를 구분지어 초기화하기
```c
circle c1 = {{10, 20}, 4.5};
```
<br>
	위 방법처럼 먼저 circle 구조체의 구조체 변수 멤버 cen에 들어갈 값을 **`{}`** 로 구분지어 초기화 할 수 있다. (**`{}`** 로 구조체 변수 멤버의 초기화를 구분지음)
<br>

- #### 중괄호를 사용하지 않고 순서대로 초기화하기
```c
circle c2 = {30, 40, 5.5};
```
<br>
	또, 중괄호로 구조체 변수 멤버를 구분하지 않고 위 처럼 순서대로 초기화 해주는 방법도 존재한다. 위 방법으로는 구조체 멤버변수 cen의 멤버 xpos에 30이, ypos에 40이 들어가고, 마지막으로 5.5가 radius에 순서대로 들어가게 된다. 
<br><br>

## 구조체를 정의하는 이유
구조체를 정의하여 서로 연관성을 지니지만, 자료형이 다른 데이터들을 하나의 새로은 자료형으로 묶으면 이러한 연관성이 있는 데이터들의 표현과 관리가 용이해 지고, 그만큼 합리적인 코드를 작성할 수 있게 된다.

```c
#include <stdio.h>

typedef struct {
	char name[20];
	char stdnum[20];
	char major[20];
	int year;
	float score;
}student;

void show_std_info(student * ptr) { // call by reference 형태의 함수호출을 수행하는 함수
	printf("Name : %s\n", ptr->name);
	printf("Student Number : %s\n", ptr->stdnum);
	printf("Major : %s\n", ptr->major);
	printf("Year : %d\n", ptr->year);
	printf("Score : %.2f\n", ptr->score);
}

int main()
{
	student stdarr[30];
	int i, num;
	
	printf("Input num : "); scanf("%d", &num);
	
	// 입력받은 학생 수 만큼 구조체 배열 stdarr에 학생 데이터 입력
	for(i = 0; i < num; i++){
		printf("Name : "); scanf("%s", stdarr[i].name);
		printf("Student Number : "); scanf("%s", stdarr[i].stdnum);
		printf("Major : "); scanf("%s", stdarr[i].major);
		printf("year : "); scanf("%d", &stdarr[i].year);
		printf("Score : "); scanf("%f", &stdarr[i].score);
	}
	
	for(i = 0; i < num; i++){
		show_std_info(&stdarr[i]); // call by reference 형태의 함수 show_std_info에 구조체 배열 stdarr의 0 부터 num 까지의 인덱스에 해당하는 구조체 변수의 주소값을 함수의 인자로서 전달. 
		puts("");
	}
}
```
다음 프로그램을 보면, **`student`** 라는 구조체의 정의를 통하여, *"학생의 정보"* 라는 주제로 서로 연관성을 지니는 데이터들인 **학생 이름`name`** , **학번 `stdnum`** , **전공 `major`** , **학년 `year`**, **학점 `score`** 을 **`student`** 라는 새로운 하나의 자료형으로 묶어주었다. 
<br>
이 과정을 통해 **`stdarr`** 이라는 구조체 배열을 선언하여 여러명의 학생의 정보가 담긴 구조체 배열을 만들수가 있었고, 또 학생들의 정보를 함수에 인자로서 전달할 경우에도 구조체 배열 **`stdarr`** 의 주소값을 보내주는 방식으로 간단히 표현이 가능해 졌다. 
<br><br>
만약, 이런 구조체라는 개념이 존재하지 않았더라면, 학생들의 정보를 저장할 때 이름과 관련된 데이터, 학번과 관련된 데이터, ... 학점에 관련된 데이터를 저장하는 배열을 각각 따로 따로 선언하여 데이터를 저장하고, 해당 데이터들을 처리하기 위해 함수의 매개변수도 각각 항목별로 여러개를 선언해주어야 할 것이다. <br>
또, 함수의 인자로서 매개변수에 전달하게 되는 데이터 또한 늘어나게 될 것이다.
즉, 쓸데없이 코드가 복잡해지고, 데이터의 표현과 관리에 있어 용이성이 매우 떨어지게 된다. 
<br><br>
때문에, **데이터의 표현과 관리의 용의성을 위해서, 보다 더 간결하고 합리적인 코드를 작성하기 위해서 구조체라는 개념은 C 프로그래밍에 있어 정말 중요한 개념이다.**<br><br>

---
