# PROJECT: HỆ THỐNG THƯ VIỆN QUẢN LÍ DANH SÁCH NGƯỜI DÙNG VÀ QUẢN LÍ SÁCH 

- Project này sẽ bao gồm quản lí thông tin người dùng trong thư viện khi họ mượn sách và quản lí các thông tin của 
các đầu sách có trong thư viện.

### Thông tin về source code:

- Viết bằng ngôn ngữ C++ 
- Build trên Visual Studio IDE 2022.

### Project bao gồm các kiến thức đã sử dụng như:

- Nhập xuất dữ liệu
- Hàm, tham trị, tham chiếu
- Thiết lập thuật toán sắp xếp nổi bọt, tìm kiếm nhị phân
- STL container: vector
- Các tính chất của hướng đối tượng: trừu trượng, đóng gói, kế thừa
- Sử dụng regex để kiểm tra việc nhập dữ liệu có hợp lệ hay không hợp lệ
- Kiểm soát ngoại lệ (exception handling)
- Thao tác đọc ghi file.

## Cấu trúc hệ thống có:
- Hàm main()
- Lớp ThuVien
- Lớp UserSystem
- Lớp BookSystem
- Lớp User
- Lớp People
- Lớp Book
- Lớp Ngay
- Các hàm kiểm tra định dạng dữ liệu
* Mối quan hệ giữa các lớp được thể hiện bằng Class Diagram

## Cấu trúc chương trình: 
Thư viện có hai hệ thống quản lí: hệ thống quản lí người mượn sách và hệ thống quản lí sách. 
Thư viện có cấu trúc cụ thể như sau:
- Cho phép mỗi người chỉ mượn 1 cuốn sách nên số lượng tối đa mà thư viện lưu trữ thông tin người mượn là 85 người(17 đầu sách * 5 số sách mỗi đầu sách).  
- Cập nhật thông tin lúc người dùng mượn sách như: ngày tháng mượn sách và thông tin người mượn vào các file txt.  

## Chức năng:
- Mượn sách
- Trả sách
- Tìm kiếm sách theo tên sách, tên tác giả và thể loại sách
- Liệt kê 
  - Các thông tin người dùng và sách mà họ mượn
  - Các sách có trong thư viện
- Báo cáo các cuốn sách mượn nhiều nhất
- Báo cáo các cuốn sách đã mượn nhưng chưa trả quá 30 ngày

### Chức năng mượn sách: 
- Khi mượn sách, người dùng điền ID riêng của mình vào để mượn sách. Sách mà họ mượn cũng có ID riêng.
- ID riêng của người dùng dùng để kiểm tra họ đã từng mượn sách hay chưa và nếu họ mượn lần tiếp theo thì lưu thông tin sách vào thông tin người mượn đó.

### Chức năng trả sách: 
- Khi trả sách, thực chất là hành động xóa thông tin sách khỏi hệ thống quản lí User.
- Khi người dùng trả hết sách thì tương đương với việc xóa thông tin người dùng ra khỏi thư viện

### Chức năng tìm kiếm: 
- Cài đặt thuật toán tìm kiếm phần tử bằng thuật toán tìm kiếm nhị phân để tìm kiếm thông tin sách trong thư viện
     
### Chức năng báo cáo các cuốn sách được mượn nhưng chưa trả quá 30 ngày:
- Sách mà người dùng đã mượn đã lưu ngày mà họ mượn khi họ đăng nhập vào thư viện lúc trước.
- Khi nhập ngày tháng hiện tại, thư viện sẽ hiển thị các sách mà người mượn đã mượn quá 30 ngày.




