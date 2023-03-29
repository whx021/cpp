
thread_example：     文件格式 elf64-x86-64


Disassembly of section .init:

0000000000401000 <_init>:
_init():
  401000:	48 83 ec 08          	sub    $0x8,%rsp
  401004:	48 8b 05 ed 2f 00 00 	mov    0x2fed(%rip),%rax        # 403ff8 <__gmon_start__>
  40100b:	48 85 c0             	test   %rax,%rax
  40100e:	74 02                	je     401012 <_init+0x12>
  401010:	ff d0                	callq  *%rax
  401012:	48 83 c4 08          	add    $0x8,%rsp
  401016:	c3                   	retq   

Disassembly of section .plt:

0000000000401020 <.plt>:
  401020:	ff 35 e2 2f 00 00    	pushq  0x2fe2(%rip)        # 404008 <_GLOBAL_OFFSET_TABLE_+0x8>
  401026:	ff 25 e4 2f 00 00    	jmpq   *0x2fe4(%rip)        # 404010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401030 <std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)@plt>:
  401030:	ff 25 e2 2f 00 00    	jmpq   *0x2fe2(%rip)        # 404018 <std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)@GLIBCXX_3.4>
  401036:	68 00 00 00 00       	pushq  $0x0
  40103b:	e9 e0 ff ff ff       	jmpq   401020 <.plt>

0000000000401040 <__cxa_atexit@plt>:
  401040:	ff 25 da 2f 00 00    	jmpq   *0x2fda(%rip)        # 404020 <__cxa_atexit@GLIBC_2.2.5>
  401046:	68 01 00 00 00       	pushq  $0x1
  40104b:	e9 d0 ff ff ff       	jmpq   401020 <.plt>

0000000000401050 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)@plt>:
  401050:	ff 25 d2 2f 00 00    	jmpq   *0x2fd2(%rip)        # 404028 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)@GLIBCXX_3.4>
  401056:	68 02 00 00 00       	pushq  $0x2
  40105b:	e9 c0 ff ff ff       	jmpq   401020 <.plt>

0000000000401060 <std::ostream::operator<<(std::ostream& (*)(std::ostream&))@plt>:
  401060:	ff 25 ca 2f 00 00    	jmpq   *0x2fca(%rip)        # 404030 <std::ostream::operator<<(std::ostream& (*)(std::ostream&))@GLIBCXX_3.4>
  401066:	68 03 00 00 00       	pushq  $0x3
  40106b:	e9 b0 ff ff ff       	jmpq   401020 <.plt>

0000000000401070 <std::thread::hardware_concurrency()@plt>:
  401070:	ff 25 c2 2f 00 00    	jmpq   *0x2fc2(%rip)        # 404038 <std::thread::hardware_concurrency()@GLIBCXX_3.4.17>
  401076:	68 04 00 00 00       	pushq  $0x4
  40107b:	e9 a0 ff ff ff       	jmpq   401020 <.plt>

0000000000401080 <std::ios_base::Init::Init()@plt>:
  401080:	ff 25 ba 2f 00 00    	jmpq   *0x2fba(%rip)        # 404040 <std::ios_base::Init::Init()@GLIBCXX_3.4>
  401086:	68 05 00 00 00       	pushq  $0x5
  40108b:	e9 90 ff ff ff       	jmpq   401020 <.plt>

0000000000401090 <std::ostream::operator<<(int)@plt>:
  401090:	ff 25 b2 2f 00 00    	jmpq   *0x2fb2(%rip)        # 404048 <std::ostream::operator<<(int)@GLIBCXX_3.4>
  401096:	68 06 00 00 00       	pushq  $0x6
  40109b:	e9 80 ff ff ff       	jmpq   401020 <.plt>

00000000004010a0 <std::ios_base::Init::~Init()@plt>:
  4010a0:	ff 25 aa 2f 00 00    	jmpq   *0x2faa(%rip)        # 404050 <std::ios_base::Init::~Init()@GLIBCXX_3.4>
  4010a6:	68 07 00 00 00       	pushq  $0x7
  4010ab:	e9 70 ff ff ff       	jmpq   401020 <.plt>

Disassembly of section .text:

00000000004010b0 <_start>:
_start():
  4010b0:	31 ed                	xor    %ebp,%ebp
  4010b2:	49 89 d1             	mov    %rdx,%r9
  4010b5:	5e                   	pop    %rsi
  4010b6:	48 89 e2             	mov    %rsp,%rdx
  4010b9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4010bd:	50                   	push   %rax
  4010be:	54                   	push   %rsp
  4010bf:	49 c7 c0 90 12 40 00 	mov    $0x401290,%r8
  4010c6:	48 c7 c1 30 12 40 00 	mov    $0x401230,%rcx
  4010cd:	48 c7 c7 92 11 40 00 	mov    $0x401192,%rdi
  4010d4:	ff 15 16 2f 00 00    	callq  *0x2f16(%rip)        # 403ff0 <__libc_start_main@GLIBC_2.2.5>
  4010da:	f4                   	hlt    
  4010db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000004010e0 <_dl_relocate_static_pie>:
_dl_relocate_static_pie():
  4010e0:	c3                   	retq   
  4010e1:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4010e8:	00 00 00 
  4010eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000004010f0 <deregister_tm_clones>:
deregister_tm_clones():
  4010f0:	b8 68 40 40 00       	mov    $0x404068,%eax
  4010f5:	48 3d 68 40 40 00    	cmp    $0x404068,%rax
  4010fb:	74 13                	je     401110 <deregister_tm_clones+0x20>
  4010fd:	b8 00 00 00 00       	mov    $0x0,%eax
  401102:	48 85 c0             	test   %rax,%rax
  401105:	74 09                	je     401110 <deregister_tm_clones+0x20>
  401107:	bf 68 40 40 00       	mov    $0x404068,%edi
  40110c:	ff e0                	jmpq   *%rax
  40110e:	66 90                	xchg   %ax,%ax
  401110:	c3                   	retq   
  401111:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  401118:	00 00 00 00 
  40111c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401120 <register_tm_clones>:
register_tm_clones():
  401120:	be 68 40 40 00       	mov    $0x404068,%esi
  401125:	48 81 ee 68 40 40 00 	sub    $0x404068,%rsi
  40112c:	48 c1 fe 03          	sar    $0x3,%rsi
  401130:	48 89 f0             	mov    %rsi,%rax
  401133:	48 c1 e8 3f          	shr    $0x3f,%rax
  401137:	48 01 c6             	add    %rax,%rsi
  40113a:	48 d1 fe             	sar    %rsi
  40113d:	74 11                	je     401150 <register_tm_clones+0x30>
  40113f:	b8 00 00 00 00       	mov    $0x0,%eax
  401144:	48 85 c0             	test   %rax,%rax
  401147:	74 07                	je     401150 <register_tm_clones+0x30>
  401149:	bf 68 40 40 00       	mov    $0x404068,%edi
  40114e:	ff e0                	jmpq   *%rax
  401150:	c3                   	retq   
  401151:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  401158:	00 00 00 00 
  40115c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401160 <__do_global_dtors_aux>:
__do_global_dtors_aux():
  401160:	80 3d 29 30 00 00 00 	cmpb   $0x0,0x3029(%rip)        # 404190 <completed.7325>
  401167:	75 17                	jne    401180 <__do_global_dtors_aux+0x20>
  401169:	55                   	push   %rbp
  40116a:	48 89 e5             	mov    %rsp,%rbp
  40116d:	e8 7e ff ff ff       	callq  4010f0 <deregister_tm_clones>
  401172:	c6 05 17 30 00 00 01 	movb   $0x1,0x3017(%rip)        # 404190 <completed.7325>
  401179:	5d                   	pop    %rbp
  40117a:	c3                   	retq   
  40117b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  401180:	c3                   	retq   
  401181:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  401188:	00 00 00 00 
  40118c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401190 <frame_dummy>:
frame_dummy():
  401190:	eb 8e                	jmp    401120 <register_tm_clones>

0000000000401192 <main>:
main():
  401192:	55                   	push   %rbp
  401193:	48 89 e5             	mov    %rsp,%rbp
  401196:	48 83 ec 10          	sub    $0x10,%rsp
  40119a:	e8 d1 fe ff ff       	callq  401070 <std::thread::hardware_concurrency()@plt>
  40119f:	89 45 fc             	mov    %eax,-0x4(%rbp)
  4011a2:	be 18 20 40 00       	mov    $0x402018,%esi
  4011a7:	bf 80 40 40 00       	mov    $0x404080,%edi
  4011ac:	e8 9f fe ff ff       	callq  401050 <std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)@plt>
  4011b1:	48 89 c2             	mov    %rax,%rdx
  4011b4:	8b 45 fc             	mov    -0x4(%rbp),%eax
  4011b7:	89 c6                	mov    %eax,%esi
  4011b9:	48 89 d7             	mov    %rdx,%rdi
  4011bc:	e8 cf fe ff ff       	callq  401090 <std::ostream::operator<<(int)@plt>
  4011c1:	be 30 10 40 00       	mov    $0x401030,%esi
  4011c6:	48 89 c7             	mov    %rax,%rdi
  4011c9:	e8 92 fe ff ff       	callq  401060 <std::ostream::operator<<(std::ostream& (*)(std::ostream&))@plt>
  4011ce:	b8 00 00 00 00       	mov    $0x0,%eax
  4011d3:	c9                   	leaveq 
  4011d4:	c3                   	retq   

00000000004011d5 <__static_initialization_and_destruction_0(int, int)>:
_Z41__static_initialization_and_destruction_0ii():
  4011d5:	55                   	push   %rbp
  4011d6:	48 89 e5             	mov    %rsp,%rbp
  4011d9:	48 83 ec 10          	sub    $0x10,%rsp
  4011dd:	89 7d fc             	mov    %edi,-0x4(%rbp)
  4011e0:	89 75 f8             	mov    %esi,-0x8(%rbp)
  4011e3:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
  4011e7:	75 27                	jne    401210 <__static_initialization_and_destruction_0(int, int)+0x3b>
  4011e9:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
  4011f0:	75 1e                	jne    401210 <__static_initialization_and_destruction_0(int, int)+0x3b>
  4011f2:	bf 91 41 40 00       	mov    $0x404191,%edi
  4011f7:	e8 84 fe ff ff       	callq  401080 <std::ios_base::Init::Init()@plt>
  4011fc:	ba 60 40 40 00       	mov    $0x404060,%edx
  401201:	be 91 41 40 00       	mov    $0x404191,%esi
  401206:	bf a0 10 40 00       	mov    $0x4010a0,%edi
  40120b:	e8 30 fe ff ff       	callq  401040 <__cxa_atexit@plt>
  401210:	90                   	nop
  401211:	c9                   	leaveq 
  401212:	c3                   	retq   

0000000000401213 <_GLOBAL__sub_I_main>:
_GLOBAL__sub_I_main():
  401213:	55                   	push   %rbp
  401214:	48 89 e5             	mov    %rsp,%rbp
  401217:	be ff ff 00 00       	mov    $0xffff,%esi
  40121c:	bf 01 00 00 00       	mov    $0x1,%edi
  401221:	e8 af ff ff ff       	callq  4011d5 <__static_initialization_and_destruction_0(int, int)>
  401226:	5d                   	pop    %rbp
  401227:	c3                   	retq   
  401228:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40122f:	00 

0000000000401230 <__libc_csu_init>:
__libc_csu_init():
  401230:	41 57                	push   %r15
  401232:	49 89 d7             	mov    %rdx,%r15
  401235:	41 56                	push   %r14
  401237:	49 89 f6             	mov    %rsi,%r14
  40123a:	41 55                	push   %r13
  40123c:	41 89 fd             	mov    %edi,%r13d
  40123f:	41 54                	push   %r12
  401241:	4c 8d 25 80 2b 00 00 	lea    0x2b80(%rip),%r12        # 403dc8 <__frame_dummy_init_array_entry>
  401248:	55                   	push   %rbp
  401249:	48 8d 2d 88 2b 00 00 	lea    0x2b88(%rip),%rbp        # 403dd8 <__init_array_end>
  401250:	53                   	push   %rbx
  401251:	4c 29 e5             	sub    %r12,%rbp
  401254:	48 83 ec 08          	sub    $0x8,%rsp
  401258:	e8 a3 fd ff ff       	callq  401000 <_init>
  40125d:	48 c1 fd 03          	sar    $0x3,%rbp
  401261:	74 1b                	je     40127e <__libc_csu_init+0x4e>
  401263:	31 db                	xor    %ebx,%ebx
  401265:	0f 1f 00             	nopl   (%rax)
  401268:	4c 89 fa             	mov    %r15,%rdx
  40126b:	4c 89 f6             	mov    %r14,%rsi
  40126e:	44 89 ef             	mov    %r13d,%edi
  401271:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  401275:	48 83 c3 01          	add    $0x1,%rbx
  401279:	48 39 dd             	cmp    %rbx,%rbp
  40127c:	75 ea                	jne    401268 <__libc_csu_init+0x38>
  40127e:	48 83 c4 08          	add    $0x8,%rsp
  401282:	5b                   	pop    %rbx
  401283:	5d                   	pop    %rbp
  401284:	41 5c                	pop    %r12
  401286:	41 5d                	pop    %r13
  401288:	41 5e                	pop    %r14
  40128a:	41 5f                	pop    %r15
  40128c:	c3                   	retq   
  40128d:	0f 1f 00             	nopl   (%rax)

0000000000401290 <__libc_csu_fini>:
__libc_csu_fini():
  401290:	c3                   	retq   

Disassembly of section .fini:

0000000000401294 <_fini>:
_fini():
  401294:	48 83 ec 08          	sub    $0x8,%rsp
  401298:	48 83 c4 08          	add    $0x8,%rsp
  40129c:	c3                   	retq   
