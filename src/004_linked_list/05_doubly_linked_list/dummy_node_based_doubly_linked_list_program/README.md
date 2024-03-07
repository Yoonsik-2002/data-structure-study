# dummy node 기반의 양방향 연결 리스트
지금까지 단순 연결 리스트, 원형 연결 리스트, 양방향 연결 리스트를 공부해 보았다. 마지막으로 연결 리스트를 마무리 하며, dummy node기반의 양방향 연결 리스트 프로그램을 직접 구현해 보았다.<br>

해당 프로그램을 구성하는 파일들은 아래 링크를 통해 들어가 볼 수 있다.<br>
[dummy_node_based_doubly_linked_list_program](https://github.com/Yoonsik-2002/data-structure-study/tree/main/src/004_linked_list/05_doubly_linked_list/dummy_node_based_doubly_linked_list_program)

일반적인 양방향 연결 리스트와 dummy node 기반의 양방향 연결 리스트를 구현해 보면서, dummy node를 기반으로 하여, 양방향 연결 리스트를 구현할 시, 아래와 같은 장점을 가질 수 있음을 알 수 있었다.<br>

**"dummy node기반의 양방향 연결 리스트의 데이터 조회 기능(`LFirst`, `LNext`) 구현 시, 일관된 방식의 코드로 기능을 구현할 수 있다."** <br>

아래 그림과 코드를 한번 보도록 하자.<br>

![스크린샷(1)](https://github.com/Yoonsik-2002/data-structure-study/assets/83572199/318c271e-56a1-43e3-89e4-d4b129f10764)<br>
