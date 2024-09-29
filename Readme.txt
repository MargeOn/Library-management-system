PROJECT: HỆ THỐNG THƯ VIỆN QUẢN LÍ DANH SÁCH NGƯỜI DÙNG VÀ QUẢN LÍ SÁCH 

Project này sẽ bao gồm quản lí thông tin người dùng trong thư viện khi họ mượn sách và quản lí các thông tin của 
các đầu sách có trong thư viện. Project được chạy bằng C++ và bao gồm các kiến thức đã sử dụng như: 
- Nhập, xuất
- Hàm, tham trị, tham chiếu
- Sắp xếp, tìm kiếm
- STL container
- Các tính chất của hướng đối tượng
- Sử dụng regex để kiểm tra việc nhập dữ liệu có hợp lệ hay không hợp lệ
- Kiểm soát ngoại lệ (exception handling)
- Thao tác đọc ghi file.
--------------------------------------------------------------------------------------------------------------------------------
Cấu trúc hệ thống có:
- Lớp ThuVien
- Lớp User
- Lớp QuanliSach
- Lớp People
- Lớp Book
- Lớp Ngày
- Các hàm kiểm tra định dạng dữ liệu
- Hàm main()
--------------------------------------------------------------------------------------------------------------------------------
- Lựa chọn thiết kế: + Lớp Thuvien sẽ quản lí một vector<User> ListUser. ListUser sẽ là danh sách các thông tin 
			của User(thể hiện các thông tin của mỗi người dùng và sách mà họ mượn) 
		     + Lớp User sẽ kế thừa từ lớp People và chứa biến thành viên là một mảng vector BorrowedBook
			(Lớp bao gồm thông tin của một người dùng và thể hiện cho việc người dùng sẽ lấy các sách mượn được). 
		     + Lớp QuanliSach sẽ quản lí một vector<Book> Listbook để lưu dữ liệu danh sách các sách trong thư viện và 
			sẽ được đọc ở file Booksetting.h

+ Đầu tiên, lớp QuanliSach sẽ quản lí một mảng Book. Đồng thời, nó sẽ lưu số lượng của mỗi đầu sách. Nên việc tạo ra lớp QuanliSach
là để lấy thông tin mỗi sách và số lượng của mỗi đầu sách.
+ Lớp User quản lí thông tin của người mượn và các sách mà họ mượn. Do đó, lớp User sẽ kế thừa từ lớp People và quản lí
một mảng vector BorrowedBook. Nên việc tạo ra lớp User chính là việc lấy thông tin của 1 người mượn và các sách mà họ mượn
+ Tiếp theo, lớp ThuVien sẽ quản lí danh sách của các thông tin của các User mượn sách. Nếu mỗi người chỉ mượn 1 cuốn sách thì số lượng
tối đa mà thư viện lưu trữ thông tin người mượn là 85 người(17 đầu sách * 5 số sách mỗi đầu sách).  
	* Lớp ThuVien sẽ thao tác và thực hiện các thay đổi trên danh sách người dùng mượn sách. Đồng thời, cập nhật thông tin ngày tháng thư 
viện và thông tin người dùng vào các file txt. 
+ Danh sách quản lí các sách vector<Book> Listbook chỉ thao tác có phương thức như truy cập vị trí của sách, đọc thông tin và kích 
thước sách. Nên việc danh sách quản lí sách cho thể lấy thông tin từ bên ngoài mà không cần là biến thành viên của ThuVien. 
Lop ThuVien chỉ quản lí thông tin của người mượn sách.
--------------------------------------------------------------------------------------------------------------------------------
- Cấu trúc mã: 
► Chức năng cập nhật ngày tháng năm và cập nhật thông tin của thư viện vào file.txt: 
	- Khi chạy chương trình sẽ liên tục cập nhật danh sách quản lí người dùng và quản lí sách vào các file Usersetting.txt và
	Booksetting.txt để lưu trữ dữ liệu và chuẩn bị cho lần chạy kế tiếp.
	- Khi người dùng mượn sách và trả sách thì cập nhật lại số lượng đầu sách đó và ghi vào file
	- Khi thư viện được chạy các lần sau, thời gian của thư viện của được cập nhật vào file và để xác định số ngày mượn sách 
	của người dùng
	-  Chức năng cập nhật có liên quan đến các thao tác mượn và trả sách, cũng như báo cáo số ngày mượn sách:
	♦ Ban đầu, khi chạy chương trình. Ta sẽ nhập ngày hiện tại khi chạy chương trình. Sau đó, thực hiện các thao tác trong thư 
	viện. Ngày tháng trong thư viện sẽ được cập nhật vào file Usersetting.txt để nó có thể xác định người dùng mượn vào ngày nào.
		+ Khi mượn sách, thông tin người dùng và ngày mượn của họ đã được lưu lại ở file "Usersetting.txt" và cập nhật 
		lại số lượng sách đó vào file Booksetting.txt.
		+ Khi trả sách, thông tin của người dùng sẽ liên tục cập nhật trong file "Usersetting.txt". Sách được trả cũng 
		không còn thông tin ngày mượn sách và quyển sách đó được thêm lại vào file Booksetting.txt
 
	♦ Sau khi chạy lại chương trình. Ta sẽ nhập ngày mới và kiểm tra có phải là hiện tại không? Bằng cách so sánh với ngày
	mà ta chạy chương trình thư viện lúc trước(khi đọc từ file Usersetting.txt lên). Cập nhật thông tin người mượn sách rồi sau 
	đó thực hiện các thao tác trong thư viện. 
		+ Khi mượn một sách A, thông tin đó sẽ lưu lại ngày hiện tại mà người dùng đó mượn sách và cập nhật vào file "User.txt".
		Dĩ nhiên, nếu họ đã từng mượn các quyển sách khác thì ngày mượn của các quyển sách đó sẽ không thay đổi khi làm thao tác 
		cập nhật file.
		+ Khi trả sách, người dùng trả sách nào thì thông tin sách ấy và ngày mượn sách sẽ được xóa và cập nhật lại 
		số lượng sách đó vào file Booksetting.txt

► Mượn sách: 1. Số lượng của mỗi quyển sách trong thư viện là 5 và chỉ cho một người mượn một quyển sách trên 1 đầu sách
	     2. Đặt trạng thái của quyển sách đó chỉ khi hết sách đó là "Borrowed", còn nếu nó còn trong thư viện thì  là "Available" 
	     3. Khi cho người dùng mượn sách thì sắp xếp lại danh sách quản lí theo ID sách trong người dùng đó
	     4. Khi thông tin người dùng được cập nhật vào Thư Viện thì sắp xếp lại danh sách quản lí theo ID user của người dùng đó 
- Tạo User mới và nhập thông tin người mượn
- Kiểm tra ID người mượn trong DS User:
	TH1: Nếu trùng ID User 		♦ Nhập index của sách muốn mượn.
	(người dùng đã mượn sách)	♦ Kiểm tra số lượng sách mà người dùng chọn.
						○ Nếu sách đã hết thì thông báo không có sách.
						○ Nếu sách còn trong thư viện thì cho người dùng mới mượn sách:
							• Kiểm tra sách (Kiểm tra ID sách) mà người dùng muốn mượn là quyển sách 
							  nào?(Không có mượn sách giống nhau):
								+ Nếu người dùng đã mượn quyển sách đó trước đây thì không cho mượn
								+ Nếu người dùng chưa mượn quyển sách đó trước đây:
									* Cập nhật thông tin người dùng (trừ ID User là không đổi) và
									  cho mượn sách.
									* Trừ đi một quyển sách của lượng sách tương ứng đó.
									* Nếu lượng sách đã hết thì đặt trạng thái của sách đó trong 
									  danh sách là "Borrowed".
									* Cập nhật số lượng sách và trạng thái sách vào file Booksetting.txt
									* Cập nhật thông tin người mượn vào file Usersetting.txt
 								+ Hỏi có muốn mượn sách tiếp hay không?
									* Nếu không thì quay về màn hình chính
									* Ngược lại, tiếp tục nhập thông tin để mượn sách
	
	TH2: Nếu không trùng ID User 	♦ Nhập index của sách muốn mượn.
	(người dùng chưa mượn sách)	♦ Kiểm tra số lượng sách mà người dùng chọn.
						○ Nếu sách đã hết thì thông báo không có sách.
						○ Nếu sách còn trong thư viện thì cho người dùng mới mượn sách:
							• Đưa thông tin Sách đã chọn vào User. 
							• Thêm User mới vào ListUser
							• Trừ đi một quyển sách của lượng sách tương ứng đó
							• Nếu lượng sách đã hết thì đặt trạng thái của sách đó trong danh sách là "Borrowed"
							• Cập nhật số lượng sách và trạng thái sách vào file Booksetting.txt
							• Cập nhật thông tin người mượn vào file Usersetting.txt
 						○ Hỏi có muốn mượn sách tiếp hay không?
							• Nếu không thì quay về màn hình chính
							• Ngược lại, tiếp tục nhập thông tin để mượn sách

► Trả sách: Khi sách đã được mượn hết và một người dùng trả lại quyển sách đó đặt trạng thái của quyển sách "Available"
- nhập ID của người dùng 
- Kiểm tra ID người trả trong DS User hay không
	TH1: Nếu không trùng ID User: 	Thông báo và kết thúc.
	TH2: Nếu trùng ID User:		♦ Nhập ID sách mà người dùng muốn trả.
					♦ Kiểm tra ID sách mà người dùng muốn trả:
						○ Nếu trùng ID sách thì cho người dùng trả sách:
							• Cộng sách đó vào mảng sách tương ứng để cập nhật số lượng của sách đó hiện có
							• Cập nhật trạng thái của sách đó trong danh sách là "Available"
								+ Nếu số sách chưa hết thì tiếp tục hỏi rằng người dùng có muốn trả sách nữa không?
									* Nếu không thì thông báo và kết thúc
									* Nếu có thì tiếp tục nhập ID sách và lặp lại như trên.
								+ Nếu số sách mà người dùng đó trả đã hết thì không hỏi nữa và xóa thông tin người 
								dùng khỏi danh sách người mượn trong thư viện
								
						○ Nếu không trùng ID sách thì (*)	
							• Sau đó, tiếp tục hỏi rằng người dùng có muốn trả sách nữa không?
								+ Nếu không thì thông báo và kết thúc
								+ Nếu có thì tiếp tục nhập ID sách và lặp lại như trên.

► Tìm kiếm: • Theo tên sách: 
		- Khi nhập tên sách là chữ cái hoa hoặc thường thì đều có thể tìm kiếm được 
		- Sắp xếp (Bubble sort) danh sách tăng dần theo tên sách(vì thao tác tìm kiếm là thuật toán tìm kiếm nhị phân nên một mảng phải được sắp xếp thứ 
		tự trước). Việc sắp xếp theo tên sách là cần thiết.
		- Tìm kiếm tên sách bằng thuật toán tìm kiếm nhị phân
			+ Nếu tìm thấy thì trả về vị trí của nó trong danh sách
			+ Không tìm thấy thì thông báo và quay về màn hình tìm kiếm
	    • Theo tác giả: 
		- Khi nhập tên tác giả là chữ cái hoa hoặc thường thì đều có thể tìm kiếm được 
		- Sắp xếp (Bubble sort) danh sách tăng dần theo tên sách(vì thao tác tìm kiếm là thuật toán tìm kiếm nhị phân nên một mảng phải được sắp xếp thứ 
		tự trước). Việc sắp xếp theo tên sách là cần thiết.
		- Tìm kiếm tên sách bằng thuật toán tìm kiếm nhị phân
			+ Nếu tìm thấy thì trả về vị trí của nó trong danh sách
			+ Không tìm thấy thì thông báo và quay về màn hình tìm kiếm
	    • Theo thể loại: Hiển thị các thể loại sách có trong danh sách. Nhập lựa chọn số theo thứ tự hiển thị tương ứng
	    • Sau khi thoát khỏi màn hình tìm kiếm thì ta nên sắp xếp lại danh sách theo ID book. Để tránh việc mảng lưu số lượng của mỗi đầu sách 
	    ánh xạ đến Listbook bị đảo lộn

► Liệt kê: - Các sách có trong thư viện: Khi một đầu sách đã mượn hết thì trạng thái của sách sẽ là "Borrowed". 
	   - Các thông tin người dùng và sách mà họ mượn

► Báo cáo các cuốn sách mượn nhiều nhất: Duyệt hệ thống quản lí sách là BookSystem, nó có lưu một mảng các số lượng của mỗi đầu 
sách trong hệ thống quản lí sách. Do đó, ta có thể so sánh và tìm được những đầu sách nào được mượn nhiều nhất 
	- So sánh đầu sách nào đã mượn đi nhiều nhất:
		+ Nếu các đầu sách bằng 5, tức là chưa có ai đến thư viện mượn sách
		+ Nếu có các đầu sách mượn nhiều nhất thì hiển thị các sách đó ra màn hình

► Báo cáo các cuốn sách đã mượn nhưng chưa trả quá 30 ngày: Hệ thống sẽ dựa trên việc nhập ngày tháng để xác định người dùng mượn
một cuốn sách vào thời gian nào. Đồng thời, cập nhật ngày mượn của người dùng đó vào file. Khi chạy lại chương trình và nhập một 
ngày sau đó, nó sẽ xác định được thời gian mượn sách có quá 30 ngày hay không. 
	* Ngày mượn sách của người dùng cũng được tính luôn vào số ngày mượn sách. 
	♦ Ban đầu chạy chương trình
		- thư viện sẽ nhập ngày hiện tại
		- nếu cho mượn sách thì cập nhật ngày hiện tại vào thuộc tính của sách. Người dùng sẽ mang thông tin ngày mượn của sách đó. Đồng thời, cập nhật
		 thông tin người dùng vào file Usersetting.txt
		- khi báo cáo những cuốn sách chưa trả quá 30 ngày vào ban đầu này. Thì sách mà người dùng mượn không thể quá 30 ngày

	♦ Chạy chương trình lượt tiếp
		○ đọc dữ liệu từ file Usersetting.txt
		○ thông tin và ngày mượn mà người dùng đã được thêm vào ListUser
		○ yêu cầu nhập ngày hiện tại của thư viện. 
			• Nếu ngày hiện tại là quá khứ của ngày trước đó thì phải nhập lại
			• Nếu thỏa mãn điều kiện nhập lại thì cho phép vào thư viện. 
				- Khi người dùng mượn sách thì sẽ cập nhật ngày hiện tại vào thuộc tính của sách đó.
				- Khi báo cáo những cuốn sách chưa trả quá 30 ngày
					+ Duyệt lần lượt các sách mà mỗi người dùng mượn và tính toán ngày mà các sách đó đã 
					mượn (ngày hiện tại trong thư viện - ngày mượn đã được đọc ở file)
					+ Nếu có sách mà ngày mượn quá 30 ngày thì sách đó sẽ hiển thị ra màn hinh và ngược lại.




