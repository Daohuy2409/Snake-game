
1. Hướng dẫn cài đặt (Với 64 bit):
- Cài đặt Visual Studio Code: nhấn vào đường link này để cài đặt:
      https://code.visualstudio.com/download#
      
     + Nhấn vào file mới tải về để khởi chạy cài đặt Visual Studio Code.
      
     + Xác nhận các điều khoản thỏa thuận.
      
     + Nhấp vào nút Next.
      
     + Sử dụng vị trí cài đặt mặc định và nhấp vào nút Next.
      
     + Sử dụng cài đặt menu Start mặc định và nhấp vào nút Next.
      
     + (Tùy chọn) Tích vào tùy chọn Add “Open with code” action to Windows Explorer file context menu.
      
     + (Tùy chọn) Tích vào tùy chọn Add “Open with code” action to Windows Explorer directory context menu.
      
     + Tích vào tùy chọn "Register Code as an editor for supported file types".
      
     + Kiểm tra tùy chọn "Add to PATH".
      
     + Nhấp vào nút Install.
      
     + Nhấp vào nút Finish.
      
     Hoàn tất bước cài đặt VScode.
      
- Cài đặt trình biên dịch MinGW-W64 GCC-7.3.0-SEH: Nhấp vào đây để cài đặt: https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-win32/seh/x86_64-7.3.0-release-win32-seh-rt_v5-rev0.7z

     + Giải nén file x86_64-7.3.0-release-win32-seh-rt_v5-rev0.7z
      
     + Copy thư mục `mingw64` vào <ROOTDIR> (Ví dụ `D:\software`)
      
     + Cài đặt đường dẫn PATH đến <ROOTDIR>\mingw64\bin
     (Tìm kiếm "PATH" trên máy tính, nhấn vào Edit the system environment variables, sau đó nhấn Environment Variables để cài đặt Path)
      
     Kiểm tra bằng cách gọi "g++" và "mingw32-make" trong terminal
      
    ![Screenshot (2)](https://user-images.githubusercontent.com/100114549/170839925-00133e66-5ac6-4b35-b9b9-e56c4856300f.png)

- Tải project Snake game từ github https://github.com/Daohuy2409/Snake-game
      Nhấn vào “Code” màu xanh, nhấp chọn “Download ZIP” để tải project về.
      
    ![Screenshot ()](https://user-images.githubusercontent.com/100114549/170840209-f8388163-d5f9-443f-9a6f-b9135a83349b.png)
      
      Giải nén tệp vừa tải.
