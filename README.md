# FLY - AND - SHOOT GAME trên AK - Embedded Base Kit

![BANNER GAME](https://github.com/DoVanTuan2805/_fly-and-shoot-game/blob/main/resource/images/banner_game.png)

**I. Giới thiệu**

**1.1. Giới thiệu sơ lược về phần cứng.**

![HARDWARE LAYOUT](https://github.com/DoVanTuan2805/_fly-and-shoot-game/blob/main/resource/images/hardware_layout.png)

- AK-Embedded Base Kit [AK Embedded Base Kit - STM32L151 - Lập trình nhúng vi điều khiển (epcb.vn)](https://epcb.vn/products/ak-embedded-base-kit-lap-trinh-nhung-vi-dieu-khien-mcu) là  evaluation kit dành cho các bạn học phần mềm nhúng nâng cao và muốn thực hành với Event - Driven.
- Các ngoại vi và MCU được tính hợp vào trong Kit:
    - Vi điều khiển chính STM32 ARM-based 32-bit MCU: [STM32L151C8T6](https://www.st.com/en/microcontrollers-microprocessors/stm32l151c8.html)
    - Truyền nhận không dây 2.4Ghz RF Transceiver ICs: [NRF24L01P-R](https://www.nordicsemi.com/products/nrf24-series)
    - Giao tiếp có dây trong công nghiệp RS485 50Mbps: [THVD1450DR](https://www.ti.com/product/THVD1450/part-details/THVD1450DR)
    - Tích hợp loa dùng để làm game Buzzers Magnetic: [MLT-8530](https://www.lcsc.com/product-detail/Buzzers_Jiangsu-Huaneng-Elec-MLT-8530_C94599.html)
    - Tích hợp NOR FLASH (32MB): [W25Q256JVEIQTR](https://www.winbond.com/hq/product/code-storage-flash-memory/serial-nor-flash/index.html?__locale=en&partNo=W25Q256JV)
    - Kết nối với các mạch ứng dụng chuẩn [Seeedstudio Grove Header HY-4AW](https://wiki.seeedstudio.com/Grove_System/)
    - Tích hợp console qua USB type C sử dụng chip USB UART Converter: [CH340E](http://www.wch-ic.com/products/CH340.html)
    - Nguyên lí của phần cứng: AK-Embedded Base Kit([schematic_ak_base_kit_2.1_60965dd0f11648eab5b41cee534e0c36.pdf (hstatic.net)](https://file.hstatic.net/1000362368/file/schematic_ak_base_kit_2.1_60965dd0f11648eab5b41cee534e0c36.pdf)
- Trò chơi "Fly and Shoot" là một tựa game kinh điển đã xuất hiện từ lâu trong làng game. Đặc biệt, hiện nay trò chơi này đã được tái tạo trên nền tảng AK-Embedded Base Kit, với việc tích hợp một hệ thống quản lý nhiệm vụ, tín hiệu, bộ đếm thời gian, và tin nhắn kết hợp với một cơ chế Event-Driven.
- Bằng cách sử dụng cơ chế Event-Driven, trò chơi có thể phản ứng linh hoạt theo sự kiện diễn ra trong trò chơi một cách tự nhiên, tạo ra trải nghiệm chơi game mượt mà và hấp dẫn hơn cho người chơi. Điều này giúp tăng cường sự tương tác và động lực cho người chơi trong quá trình tham gia vào trò chơi "Fly and Shoot".

**1.2. Màn hình Menu**

![SCREEN MENU](https://github.com/DoVanTuan2805/_fly-and-shoot-game/blob/main/resource/images/screen_menu.png)

- PLAY: Bắt đầu trò chơi.
- SETTING: Cài đặt cái thông số cho trò chơi mode(chế độ), missile(đạn), âm thanh(bật/tắt).
- TUTORIAL: QR hướng dẫn trò chơi.
- HISTORY: Lưu lịch trò điểm sau những lần chơi.
- EXIT: Thoát màn hình menu.

**1.3. Các đối tương hoạt động trong game.**

![INTRO OBJECT IN GAME](https://github.com/DoVanTuan2805/_fly-and-shoot-game/blob/main/resource/images/intro_object_game.png)

| Đối tượng | Ý nghĩa | Người chơi tác động | Tự động tác động |
| --- | --- | --- | --- |
| PLANE | Tàu bay | Di chuyển tàu bay đi lên  | Di chuyển tàu bay đi xuống, chạm quặng, bom sẽ tạo ra vụ nổ và kết thúc game |
| MISSILE | Đạn | Bắn ra đạn phá hủy quặng, bom | Di chuyển, tạo ra vụ nổ khi chạm quặng, bom, tạo ra điểm khi chạm quặng |
| MINE | Quặng | Không | Di chuyển, tự động tạo ra |
| BOM | Bom | Không | Di chuyển, tự động tạo ra |
| EXPLOSION | Vụ Nổ | Không | Vụ nổ xảy ra khi đạn chạm quặng hoặc bom |
| TUNNEL WALL | Đường hầm | Không | Di chuyển bản đồ |

**1.4. Cách chơi của game.**

Người chơi có thể điều khiển tàu đi lên (UP) hoặc để tàu bay tự động rơi xuống để né các quặng và bom không chạm vào máy bay. Đồng thời cũng không được để tàu bày chạm vào đường hầm (TUNNEL WALL). 

Tăng độ khó bằng cách vào cài đặt và chỉnh mode (EASY, NORMAL, HARD).

Có thể bắn đạn bằng cách nhấn nút MODE khi đạn chạm trúng các quặng sẽ tạo ra điểm. Số đạn có thể tùy chỉnh được trong SETTING và được giới hạn tối đa là 5 viên.

*Cách tính điểm:*

- Quặng nhỏ sẽ có 1 điểm khi bắn trúng.
- Quặng lớn sẽ có 2 điểm khi bắn trúng.
- Bom sẽ không có điểm khi bắn trúng.

Số điểm sẽ được lưu khi trò chơi kết thúc. Khi trò chơi kết thúc nhấn MODE để chơi tiếp, nhấn DOWN để quay trở về menu.

**II. Thiết kế các Task, Signal trong game.**

**2.1. Event - Driven hoạt động như thế nào ?**

![INTRO EVENT DRIVEN](https://github.com/DoVanTuan2805/_fly-and-shoot-game/blob/main/resource/images/intro_event_driven.png)

                                             *Nguồn: Automatic Control Programming*

- Event Driven nói một cách dễ hiểu là một hệ thống gửi thư (gửi message) để thực thi các công việc. Trong đó, Task đóng vai trò là người nhận thư, Signal đại diện cho nội dung công việc. Task & Signal nền tảng của một hệ Event Driven.
- Thông thường mỗi Task sẽ nhận một nhóm công công việc nào nào đó, ví dụ: quản lý state-machine, quản lý hiển thị của màn hình, quản lý việc cập nhật phần mềm, quản lý hệ thống watchdog ...
- Message được chia làm 2 loại chính, Message chỉ chứa Signal, hoặc vừa chứa Signal và Data. Message tương đương với Signal.
- Chỗ thực thi một công việc nào đó thì mình gọi là Handler.

Chi tiết các khái niệm các bạn tham khảo tại bài viết: [AK Embedded Base Kit - STM32L151 - Event Driven: Task & Signal](https://epcb.vn/blogs/ak-embedded-software/ak-embedded-base-kit-stm32l151-event-driven-task-signal)  

**2.2. Task và Signal trong Fly - And - Shoot.**

*Các Task và Priority trong game:*

| TASK ID | PRIORITY | HANDLER |
| --- | --- | --- |
| FS_GAME_TASK_DISPLAY_GAME_ON_ID | TASK_PRI_LEVEL_4	 | task_scr_fs_game_on_handle |
| FS_GAME_TASK_PLANE_ID				 | TASK_PRI_LEVEL_4	 | task_fs_plane_hanle		 |
| FS_GAME_TASK_MISSLE_ID				 | TASK_PRI_LEVEL_4	 | task_fs_missile_handle		 |
| FS_GAME_TASK_WALL_ID				 | TASK_PRI_LEVEL_4 | task_fs_wall_handle		 |
| FS_GAME_TASK_EXPLOSION_ID			 | TASK_PRI_LEVEL_4	 | task_fs_explosion_handle	 |
| FS_GAME_TASK_BOM_ID				 | TASK_PRI_LEVEL_4 | task_fs_bom_handle			 |
| FS_GAME_TASK_MINE_ID				 | TASK_PRI_LEVEL_4 | task_fs_mine_handle		 |
| FS_GAME_TASK_DISPLAY_GAME_OVER_ID	 | TASK_PRI_LEVEL_4	 | task_scr_fs_game_over_handle	 |

    **

![Intro Object Game](https://github.com/DoVanTuan2805/_fly-and-shoot-game/blob/main/resource/images/intro_object_game.png)

         *Chi tiết các signal trong các Task:*

*Task ID*:  Mỗi task được tạo ra cho một đối tượng khác nhau trong hệ thống và có nhiệm vụ nhận các công việc khác nhau. Các task hoàn toàn tác biệt luồng logic với nhau.

*Priority*: Mức độ ưu tiên của các task. Như trong ảnh bên trên ta có thể thấy độ ưu tiên của các task là bằng nhau. Tức là khi các task có priority bằng nhau đều có sự kiện thì hệ thống sẽ sử lí task nào vào trước.

*Handler*: Là nơi sử lí các tín hiệu của sự kiện khi xảy ra tác động.

Signal: Mỗi task sẽ có nhiều signal khác nhau nhằm mục đích xử lí các nhiệm vụ khác nhau của các đối tượng.                              

Ví dụ: Ở task missile sẽ có signal (FS_GAME_MISSILE_PUSH_SIG) sẽ có nhiệm vụ tạo ra đạn, còn (FS_GAME_MISSLE_MOVE_SIG) sẽ có nhiệm vụ di chuyển nếu có đạn.

Các task có thể đồng bộ hóa và trao đổi dữ liệu bằng cách bắn message qua các task đi kèm với signal.

Có 2 loại message khác nhau:

- Messge chỉ mang theo Signal, không chứa data
- Message chứa Signal và mang theo cả data.

**2.3. Sơ đồ quá trình của game**

![Sequence After Game On](https://github.com/DoVanTuan2805/_fly-and-shoot-game/blob/main/resource/images/Sequence/sequence_after_game_on.png)

                                                   *Hình 2.3.1: Sequence after game on*

![Sequence Game Active](https://github.com/DoVanTuan2805/_fly-and-shoot-game/blob/main/resource/images/Sequence/sequence_game_active.png)

                                                  *Hình 2.3.2: Sequence when game run*

![Sequence Game Over](https://github.com/DoVanTuan2805/_fly-and-shoot-game/blob/main/resource/images/Sequence/sequence_game_over.png)

                                                  *Hình 2.3.3: Sequence game over*

*Action after run game*

| SCREEN_ENTRY | Khi người dùng bắt đầu chơi game |
| --- | --- |
| FS_GAME_DISPLAY_ON_TICK | Signal do timer gửi đến với chu kì 100ms cập nhật lại màn hình |
| FS_GAME_PLANE_UP_SIG | Cài đặt thông số mặc định cho tàu bay |
| FS_GAME_PLANE_ON_TICK_SIG | Signal do timer gửi đến với chu kì 100ms giúp tàu bay đi xuống |
| FS_GAME_MINE_RESET_SIG | Cài đặt thông số mặc định cho quặng |
| FS_GAME_MINE_ON_TICK_SIG | Signal do timer gửi đến với chu kì 150ms dùng để di chuyển quặng |
| FS_GAME_MINE_PUSH_SIG | Signal do timer gửi đến với chu kì 1500ms dùng để tạo thêm quặng |
| FS_GAME_BOM_RESET_SIG | Cài đặt lại tất cả các thông số bom |
| FS_GAME_BOM_ON_TICK_SIG | Signal do timer gửi đến với chu kì 150ms dùng để di chuyển bom |
| FS_GAME_BOM_PUSH_SIG | Signal do timer gửi đến với chu kì 1800ms dùng để tạo thêm bom |
| FS_GAME_MISSLE_RESET_SIG | Cài đặt lại tất cả các thông số cho đạn |
| FS_GAME_WALL_RESET_SIG | Cài đặt lại tất cả các thông số cho hầm |
| FS_GAME_WALL_ON_TICK_SIG | Signal do timer gửi đến với chu kì 100ms dùng để di chuyển hầm |
| FS_GAME_EXPLOSION_RESET_SIG | Cài đặt lại tất cả các thông số cho vụ nổ |
| FS_GAME_EXPLOSION_ON_TICK_SIG | Signal do timer gửi đến với chu kì 150ms dùng để tạo hoạt ảnh cho vụ nổ |
| fs_state_game | Biến lưu trạng thái của game |

*Action normal*

| FS_GAME_DISPLAY_ON_TICK | Signal do timer gửi đến với chu kì 100ms |
| --- | --- |
| FS_GAME_PLANE_CRASH_SIG | Signal kiểm tra tàu bay có chạm vào bom, quặng hay tường  |
| FS_GAME_DISPLAY_OVER_ON_TICK | Signal tạo ra khoảng chờ để chuyển đến màn hình game over |
| FS_GAME_MISSLE_ON_TICK_SIG | Signal do timer gửi đến với chu kì 100ms dùng để di chuyển bom |
| FS_GAME_MISSLE_RESET_SIG | Signal kiểm tra đạn có chạm vào bom hay quặng  |
| RELOAD SCREEN | Giúp cập nhật lại toàn bộ màn hình |

*Action player*

| FS_GAME_PLANE_UP_SIG | Player nhấn [Up] tạo ra signal giúp tàu bay đi lên |
| --- | --- |
| FS_GAME_MISSLE_PUSH_SIG | Player nhấn [Mode] tạo ra signal giúp bắn ra đạn |

*Action game over*                          

| timer_remove | Xóa các timer chạy cho các đối tượng trong game |
| --- | --- |
| Write score to eeprom and read history | Lưu lại điểm đạt được trong game vào trong bộ nhớ eeprom |

                                                     **

**III. Chi tiết code các đối tượng trong game**

 **3.1 Tàu bay (Plane)**

Mỗi đối tượng sẽ có những thông số để điều khiển những đối tượng đó.

```cpp
typedef struct
{
    int8_t x;
    int8_t y;
}fs_game_coordinate_t;

typedef struct {
    bool visible;
    fs_game_coordinate_t coordinate;
} fs_plane_info_t;

fs_plane_infor_t fs_plane;
```

Ở đoạn code trên thông số của tàu bay sẽ được lược vào kiểu dữ liệu struct mục đích nhằm để dễ quản lí. Ở trong struct trên có lồng thêm struct “fs_game_coordinate_t” nhằm để quản lí dễ dàng về tạo độ cho tàu bay. Biến “visble“là nhằm quản lí trạng thái ẩn hiện của tàu bay.  

![Sequence Plane](https://github.com/DoVanTuan2805/_fly-and-shoot-game/blob/main/resource/images/Sequence/sequence_plane.png)

                                                       *Hình 3.1.1: Plane sequence*

Tóm tắt cách giải quyết vấn đề:

Khi người dùng bắt đầu trò chơi sẽ cài đặt timer với chu kì 100ms và bắn message FS_GAME_PLANE_SETUP_SIG nhằm để cài đặt thông số mặc định cho tàu bay

Timer được cài đặt cứ mỗi 100ms sẽ bắn message đến FS_GAME_PLANE_ON_TICK_SIG và cũng bắn đến FS_GAME_PLANE_CRASH_SIG.

- Tiếp đó FS_GAME_PLANE_ON_TICK_SIG sẽ tính toán tọa độ “y” giúp tàu bay đi xuống. 

- Đồng thời cũng bắn message đến FS_GAME_PLANE_CRASH_SIG để kiểm tra tàu bay có chạm vào tường hầm, quặng hay bom, nếu chạm một trong những vật cản sẽ cài đặt timer để bắn message đến FS_GAME_DISPLAY_OVER_ON_TICK nhằm tạo khoảng chờ trước khi game over, sau đó sẽ gửi tọa độ đến FS_GAME_EXPLOSION_PUSH_SIG để tạo hiệu ứng vụ nổ.

Khi người chơi nhấn nút [UP] sẽ bắn message đến FS_GAME_PLANE_UP_SIG giúp giảm tọa độ “y” của tàu bay. 

Đoạn code trong source:

Tín hiệu FS_GAME_PLANE_SETUP_SIG:

```cpp
static inline void fs_game_plane_setup() {
    fs_plane.coordinate.x = 5;
    fs_plane.coordinate.y = 15;
    fs_plane.visible = true;
}
```

Tín hiệu FS_GAME_PLANE_DOWN_SIG :

```cpp
static inline void fs_game_plane_down() {
    fs_plane.coordinate.y += FS_PLANE_Y_DOWN;
    if (fs_plane.coordinate.y > MAP_HEIGHT) {
        fs_plane.visible = false;
        fs_plane.coordinate.y = MAX_LCD_HEIGHT;
    }
}
```

Tín hiệu FS_GAME_PLANE_UP_SIG :

```cpp
static inline void fs_game_plane_up() {
    fs_plane.coordinate.y -= FS_PLANE_Y_UP;
}
```

Tín hiệu FS_GAME_PLANE_CRASH_SIG :

```cpp
static inline void fs_game_wall_crash() {
	// code
}
static inline void fs_game_mine_crash() {
	// code
}
static inline void fs_game_bom_crash() {
	// code
}
static inline void fs_game_plane_crash() {
    if(fs_state_game == FS_GAME_ON){
        fs_game_mine_crash();
        fs_game_bom_crash();
        fs_game_wall_crash();
    }
}
```

Cài timer khi tàu bay va chạm :

```cpp
timer_set(FS_GAME_TASK_DISPLAY_GAME_OVER_ID, FS_GAME_DISPLAY_OVER_ON_TICK, AC_GAME_OVER_INTERNAL, TIMER_ONE_SHOT);
```

Lấy tọa độ khi tàu bay va chạm :

```cpp
fs_explosion.coordinate.x = fs_plane.coordinate.x;
fs_explosion.coordinate.y = fs_plane.coordinate.y;
fs_explosion.ver = VER_I;
task_post_dynamic_msg(FS_GAME_TASK_EXPLOSION_ID, FS_GAME_EXPLOSION_PUSH_SIG, (uint8_t *)&fs_explosion, sizeof(fs_explosion));
```

**3.2. Đạn (Missile)**

![Sequence Missile](https://github.com/DoVanTuan2805/_fly-and-shoot-game/blob/main/resource/images/Sequence/sequence_missile.png)

                                                      *Hình 3.2.1 Missile sequence*

Tương tự như tàu bay, đạn cũng có những biến quản lí các thông số:

```cpp
class fs_missile_info_t {
   private:
   public:
    bool visible;
    fs_game_coordinate_t coordinate;
    fs_missile_info_t(uint8_t x, uint8_t y, bool visible) {
        this->coordinate.x = x;
        this->coordinate.y = y;
        this->visible = visible;
    }
};

vector<fs_missile_info_t> fs_vec_missile;
```

Chức năng biến của missile cũng tương tự như “Plane”. Xem lại 3.1 để hiểu rõ hơn.

Giải thích missile sequence:

Khi bắt đầu vào game sẽ có signal “SCREEN_ENTRY” và sẽ đặt lại các thông số cho missile, và xóa missile trước đó nếu có. Và sẽ cài đặt timer cho mỗi 100ms sẽ bắn message đến FS_GAME_MISSILE_ON_TICK, FS_GAME_MISSILE_CRASH_SIG. 

- FS_GAME_MISSILE_ON_TICK sẽ di chuyển đạn (nếu có).

- FS_GAME_MISSILE_CRASH_SIG sẽ kiểm tra missile có va chạm vào bom hay quặng không? Nếu có sẽ bắn tạo ra vụ nổi bằng cách bắn message đến FS_GAME_EXPLOSION_PUSH_SIG kèm theo data là tạo độ vụ nổ.