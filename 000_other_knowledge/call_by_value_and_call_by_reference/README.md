## Call-by-value 와 Call-by-reference
Call-by-value와 Call-by-reference는 **함수호출**과 관련된 개념이다. 

- #### Call-by-value
  Call-by-value는 함수호출 시, 단순히 값을 전달하는 형태의 함수호출을 의미하며 이 경우, 함수가 호출되면 **인자로 전달되는 변수의 값이(변수에 저장되어 있는 값이) 해당 함수의 매개변수에 복사되어 전달된다.**
  ```c
  ...
  void ex_func(int n) {
    ...
  }
  int main()
  {
    int num = 10;
    ex_func(num); // ex_func 함수가 호출되면 인자로 전달되는 변수 num에 저장되어 있는 값 10이 복사되어 해당 함수의 매개변수 n에 전달됨
    ...
  }
  ```
  다음 코드를 보면, 10 이라는 값을 저장하고 있는 int형 변수 **`num`** 이 함수 **`ex_func`** 에 인자로서 **`ex_func`** 의 매개변수 **`n`** 에 전달된다.<br>
  
  이 경우는 단순히 값을 전달하는 형태의 함수호출인 Call-by-value로, 해당 함수 호출이 일어나면 **인자로 전달되는 변수 num에 저장되어 있는 값 10이 복사되어 해당 함수의 매개변수 n에 전달되게 된다.**<br>
  
  이러한 Call-by-value 형태의 함수를 사용하는 경우에 발생하는 현상은 다음과 같다.<br>
  - 값이 복사되어 전달되기 때문에 인자로 전달된 변수 **`num`** 과 복사된 값을 전달받은 **`ex_func`** 의 매개변수 **`n`** 은 값은 같지만 별개의 변수가 된다. 즉, 둘은 별개의 변수이기 때문에 **`ex_func`** 에서 **`n`** 의 값을 변경하였다고 해서 **`num`** 의 값의 변경으로 이어지지 않는다. (매개변수의 값을 변경해도 원래의 전달된 변수의 값에는 영향을 미치지 않음)<br><br>
  - Call-by-value 형태의 함수에서는 함수 외부에 선언된 변수에 접근이 불가능하다. 이유는 위의 내용과 비슷하다. 애초에 단순히 값이 전달되는 Call-by-value 함수의 매개변수에는 값이 복사되어 전달되기 때문에 함수 외부에 선언된 변수에 접근할 수 있는 방법이 존재하지 않는다. 
  복사되어 매개변수에 전달된 값의 주소값과 인자로서 전달된 값의 주소값은 다름!<br><br>
  ```c
  #include <stdio.h>

  void exfunc(int n) {
	  printf("매개변수 n에 저장된 값 : %d\n", n);
	  printf("매개변수 n의 주소값 : %p\n", &n);
  }

  int main()
  {
	  int n = 10;
	  printf("변수 n에 저장된 값 : %d\n", n);
	  printf("변수 n의 주소값 : %p\n", &n);
	  puts("");
	
	  exfunc(n);
  }
  ```
  ```c
  [실행결과]
  변수 n에 저장된 값 : 10
  변수 n의 주소값 : 0x7fff30c3f7a4

  매개변수 n에 저장된 값 : 10
  매개변수 n의 주소값 : 0x7fff30c3f78c
  ```
- #### Call-by-reference
  Call-by-reference는 함수호출 시, 참조할 수 있는 값의 주소값(메모리 접근에 사용되는 주소값)을 전달하는 형태의 함수호출을 의미한다. 이 경우에는 함수가 호출되면 함수에 단순히 값을 전달하는 대신, 값의 주소값을 매개변수에 전달하게 된다. <br><br>
  이때, 값의 주소값이 인자로서 함수의 매개변수에 전달될 때 해당 주소값은 복사되어 전달되게 된다. 어? 그러면 이것도 Call-by-value라고 할 수 있지 않은가? 라고 생각할 수 있다.
  맞는 말이다.<br><br>
  사실 엄밀히 따지자면 C언어에서의 방식은 주소값 자체를 복사해서 넘겨주는 것이므로 Call-by-value이다. 또한 이렇게 주소값을 복사해서 넘겨주는 방식을 Call-by-address 방식이라고 한다.<br>
  **공식적으로, c언어에서는 Call-by-reference를 지원하지 않는다. 그러나 의미적, 결과적으로 Call-by-address를 사용해서 Call-by-reference 와 같이 사용할 수 있기 때문에 일반적으로 c언어에서 포인터를 이용해 주소값을 넘겨주는 방식을 Call-by-reference 라고 설명하는 곳도 많다.** (참고 - [edu.goorm.io](https://edu.goorm.io/learn/lecture/201/%ED%95%9C-%EB%88%88%EC%97%90-%EB%81%9D%EB%82%B4%EB%8A%94-c%EC%96%B8%EC%96%B4-%EA%B8%B0%EC%B4%88/lesson/1271949/call-by-value-call-by-reference))<br><br>
  아무튼 나는 일단 Call-by-reference로 부르도록 하겠다. 이러한 Call-by-reference 형태의 함수를 사용하는 경우에 발생하는 현상은 다음과 같다.<br>
  - 외부에서 선언된 변수의 주소값이 포인터 변수 형태의 매개변수에 전달되기 때문에, 해당 매개변수는 주소값을 전달해준 외부에 선언된 변수에 접근할 수 있게된다. <br>
  즉, **`*매개변수`** 는 해당 함수 외부에서 선언되어 주소값을 전달한 변수를 의미하게되어, **`*매개변수`** 의 값의 변경은 곧 주소값을 전달해준 외부에서 선언된 변수의 값의 변경과 이어지게 된다. 
  
  - 외부에서 선언된 변수의 주소값을 해당 함수의 포인터 변수형태의 매개변수가 저장하고 있기 때문에, **함수 내에서 함수 외부에 선언된 변수에 접근이 가능하게 된다.** <br><br>
  ```c
  #include <stdio.h>

  void ex_func(int * ptrInt) {
	  printf("--ex_func 함수 실행--\n");
	  puts("");
	  printf("ex_func 함수의 매개변수 ptrInt에 전달된 값 : %p\n", ptrInt);
	  printf("ptrInt에 전달된 주소값을 가진 함수 외부에 선언된 변수 num에 저장된 값 : %d\n", *ptrInt);
	  printf("*ptrInt의 값을 20으로 변경\n");
	  puts("");
	  printf("--ex_func 함수 종료--\n");
	  *ptrInt = 20;
  }

  int main()
  {
	  int num = 10;

	  printf("변수 num의 주소값 : %p\n", &num);
	  printf("변수 num에 저장된 값 : %d\n", num);
	  puts("");
	
	  ex_func(&num);
	  puts("");
	  printf("변경된 num의 값 : %d\n", num);
  }
  ```
  ```c
  [실행결과]
  변수 num의 주소값 : 0x7ffee39b5774
  변수 num에 저장된 값 : 10

  --ex_func 함수 실행--

  ex_func 함수의 매개변수 ptrInt에 전달된 값 : 0x7ffee39b5774
  ptrInt에 전달된 주소값을 가진 함수 외부에 선언된 변수 num에 저장된 값 : 10
  *ptrInt의 값을 20으로 변경

  --ex_func 함수 종료--

  변경된 num의 값 : 20
  ```
  <br><br>
---
  
  
  
	

  
  
  
