## 🧾 구조체
구조체를 공부하기 전에, 자료구조에 대한 개념을 간단히 짚고 넘어가 보도록 하겠다. 
### 자료구조란?
프로그램이란 데이터를 표현(저장)하고, 그렇게 표현된 데이터를 처리하는 것이다. 때문에 일반적인 프로그램은 논리적으로 따져보면 크게 데이터를 표현하는 **자료구조**와 표현된 데이터를 처리하는 **알고리즘**으로 나눌 수 있다. 

위에서 말했듯이, 자료구조란 데이터의 표현을 담당하는 개념이다. <br>이때, 데이터의 표현은 데이터의 저장이라는 개념도 내포한다.
이러한 이유로 **넓은 의미에서 프로그램에 사용되는 일반 변수, 구조체, 배열 또한 데이터의 표현(저장)과 관련된 개념이므로, 자료구조에 속한다.**

### 구조체(struct)
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
  서로 연관성이 있지만, 자료형이 다른(다양한) 데이터 **`stdID`**, **`name[20]`**, **`score`** 는 형 정의문을 통해 새롭게 정의된 자료형 **`stdData`** 라는 새로운 하나의 자료형으로 묶이게 된다.*br>
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

#### 구조체 변수의 선언과 초기화
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
다음은 구조체 배열을 이용하여 만든 간단한 전화번호부 프로그램이다. 
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







  
