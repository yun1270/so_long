# So_long

>Being a developer is a great thing for creating your own game. But a good game needs some good assets. for 2D games, you should search for tiles, tilesets, sprites, and sprite sheets. Thankfully some talented artists are willing to share their works on platforms like: itch.io 
>
>Whatever you do try to respect the works of others



#### allowed function

- open, close, read, write, malloc, free, perror, strerror, exit
- All functions of the MinilibX



#### Pipex should

- miniLibX를 사용해야 합니다. 운영 체제에서 사용할 수 있는 버전 또는 원본에서 사용할 수 있는 버전입니다. 소스를 사용하기로 선택한 경우 위에 나와 있는 공통 지침 파트에 나와 있는 것과 동일한 규칙을 libft에 적용해야 합니다.
- 다른 창으로 변경, 최소화 등 창 관리가 원활해야 합니다.



지도는 3개의 벽, 수용체, 그리고 여유 공간으로 구성될 것입니다.

- 참가자의 목표는 지도에 있는 모든 수집품을 수집한 후 최소한의 움직임으로 탈출하는 것이다.
-  이동할 때마다 현재 이동 횟수가 셸에 표시되어야 합니다.
- 플레이어가 위, 아래, 왼쪽, 오른쪽으로 이동할 수 있어야 합니다.
- 2D 보기(하향식 또는 프로필)를 사용합니다.
- 게임을 실시간으로 진행할 필요는 없습니다.
- 플레이어는 벽 안으로 이동할 수 없습니다.



- 이 프로그램은 이미지를 창에 표시하고 다음 규칙을 따릅니다.
  - W, A, S, D Key를 이용하여 Main Haracter를 이동합니다.
  - ESC를 누르면 창을 닫고 프로그램을 종료해야 합니다.
  - 창에 있는 빨간 X 표시는 창을 닫고 프로그램을 완전히 종료해야 합니다.
- 프로그램에서 .ber 파일과 함께 지도 설명 파일을 첫 번째 인수로 받아들여야 합니다.
  - 지도는 빈칸 0자, 벽 1자, 수집 가능한 C자, 지도 종료의 경우 E자, 플레이어의 출발 위치의 경우 P자 등 5자만 가능합니다.
  - 다음은 간단한 유효한 지도입니다.
    1111111111111
    10010000000C1
    1000011111001
    1P0011E000001
    1111111111111
  - 지도는 반드시 닫거나 벽으로 둘러싸야 하며, 그렇지 않을 경우 반드시 오류를 반환해야 합니다.
  - 지도에는 적어도 하나의 출구, 하나의 수집 가능, 하나의 시작 위치가 있어야 합니다.
  - 지도에 유효한 경로가 있는지 확인할 필요가 없습니다.
  - 지도는 직사각형이어야 한다.
  - 지도의 규칙을 따르는 한 어떤 종류의 지도라도 구문 분석할 수 있어야 합니다.
  - Another minimal .ber map:
    1111111111111111111111111111111111
    1E0000000000000C00000C000000000001
    1010010100100000101001000000010101
    1010010010101010001001000000010101
    1P0000000C00C0000000000000000000C1
    1111111111111111111111111111111111
- 파일에 잘못된 구성이 있는 경우, 프로그램을 정상적으로 종료하고 "Error\n"을 반환한 후 사용자가 선택한 명시적 오류 메시지를 반환해야 합니다.