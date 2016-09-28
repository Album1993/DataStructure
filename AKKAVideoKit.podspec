Pod::Spec.new do |s|
s.name             = "AKKAVideoKit"
s.version          = "1.0.0"
s.summary          = "Video capture"
s.homepage         = "https://github.com/Album1993/AACPlayer"
s.license          = 'Code is MIT, then custom font licenses.'
s.author           = { "zhangyiming" => "ymzhangvip@gmail.com" }
s.source           = { :git => "https://zhangyiming@bitbucket.org/zhangyiming/akkavideokit.git", :tag => s.version }

s.platform     = :ios, '8.0'
s.requires_arc = true

s.source_files = 'AKKAAvKit/**/*'
s.public_header_files = 'AKKAAvKit/**/*.h'   #公开头文件地址

end
