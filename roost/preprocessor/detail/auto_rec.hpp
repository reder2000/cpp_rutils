# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Roost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.roost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.roost.org for most recent version. */
#
# include <roost/preprocessor/config/config.hpp>
#
# if ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_DMC()
#     include <roost/preprocessor/detail/dmc/auto_rec.hpp>
# else
#
# ifndef ROOST_PREPROCESSOR_DETAIL_AUTO_REC_HPP
# define ROOST_PREPROCESSOR_DETAIL_AUTO_REC_HPP
#
# include <roost/preprocessor/control/iif.hpp>
#
# /* ROOST_PP_AUTO_REC */
#
# define ROOST_PP_AUTO_REC(pred, n) ROOST_PP_NODE_ENTRY_ ## n(pred)
#
# define ROOST_PP_NODE_ENTRY_256(p) ROOST_PP_NODE_128(p)(p)(p)(p)(p)(p)(p)(p)
# define ROOST_PP_NODE_ENTRY_128(p) ROOST_PP_NODE_64(p)(p)(p)(p)(p)(p)(p)
# define ROOST_PP_NODE_ENTRY_64(p) ROOST_PP_NODE_32(p)(p)(p)(p)(p)(p)
# define ROOST_PP_NODE_ENTRY_32(p) ROOST_PP_NODE_16(p)(p)(p)(p)(p)
# define ROOST_PP_NODE_ENTRY_16(p) ROOST_PP_NODE_8(p)(p)(p)(p)
# define ROOST_PP_NODE_ENTRY_8(p) ROOST_PP_NODE_4(p)(p)(p)
# define ROOST_PP_NODE_ENTRY_4(p) ROOST_PP_NODE_2(p)(p)
# define ROOST_PP_NODE_ENTRY_2(p) ROOST_PP_NODE_1(p)
#
# define ROOST_PP_NODE_128(p) ROOST_PP_IIF(p(128), ROOST_PP_NODE_64, ROOST_PP_NODE_192)
#    define ROOST_PP_NODE_64(p) ROOST_PP_IIF(p(64), ROOST_PP_NODE_32, ROOST_PP_NODE_96)
#        define ROOST_PP_NODE_32(p) ROOST_PP_IIF(p(32), ROOST_PP_NODE_16, ROOST_PP_NODE_48)
#            define ROOST_PP_NODE_16(p) ROOST_PP_IIF(p(16), ROOST_PP_NODE_8, ROOST_PP_NODE_24)
#                define ROOST_PP_NODE_8(p) ROOST_PP_IIF(p(8), ROOST_PP_NODE_4, ROOST_PP_NODE_12)
#                    define ROOST_PP_NODE_4(p) ROOST_PP_IIF(p(4), ROOST_PP_NODE_2, ROOST_PP_NODE_6)
#                        define ROOST_PP_NODE_2(p) ROOST_PP_IIF(p(2), ROOST_PP_NODE_1, ROOST_PP_NODE_3)
#                            define ROOST_PP_NODE_1(p) ROOST_PP_IIF(p(1), 1, 2)
#                            define ROOST_PP_NODE_3(p) ROOST_PP_IIF(p(3), 3, 4)
#                        define ROOST_PP_NODE_6(p) ROOST_PP_IIF(p(6), ROOST_PP_NODE_5, ROOST_PP_NODE_7)
#                            define ROOST_PP_NODE_5(p) ROOST_PP_IIF(p(5), 5, 6)
#                            define ROOST_PP_NODE_7(p) ROOST_PP_IIF(p(7), 7, 8)
#                    define ROOST_PP_NODE_12(p) ROOST_PP_IIF(p(12), ROOST_PP_NODE_10, ROOST_PP_NODE_14)
#                        define ROOST_PP_NODE_10(p) ROOST_PP_IIF(p(10), ROOST_PP_NODE_9, ROOST_PP_NODE_11)
#                            define ROOST_PP_NODE_9(p) ROOST_PP_IIF(p(9), 9, 10)
#                            define ROOST_PP_NODE_11(p) ROOST_PP_IIF(p(11), 11, 12)
#                        define ROOST_PP_NODE_14(p) ROOST_PP_IIF(p(14), ROOST_PP_NODE_13, ROOST_PP_NODE_15)
#                            define ROOST_PP_NODE_13(p) ROOST_PP_IIF(p(13), 13, 14)
#                            define ROOST_PP_NODE_15(p) ROOST_PP_IIF(p(15), 15, 16)
#                define ROOST_PP_NODE_24(p) ROOST_PP_IIF(p(24), ROOST_PP_NODE_20, ROOST_PP_NODE_28)
#                    define ROOST_PP_NODE_20(p) ROOST_PP_IIF(p(20), ROOST_PP_NODE_18, ROOST_PP_NODE_22)
#                        define ROOST_PP_NODE_18(p) ROOST_PP_IIF(p(18), ROOST_PP_NODE_17, ROOST_PP_NODE_19)
#                            define ROOST_PP_NODE_17(p) ROOST_PP_IIF(p(17), 17, 18)
#                            define ROOST_PP_NODE_19(p) ROOST_PP_IIF(p(19), 19, 20)
#                        define ROOST_PP_NODE_22(p) ROOST_PP_IIF(p(22), ROOST_PP_NODE_21, ROOST_PP_NODE_23)
#                            define ROOST_PP_NODE_21(p) ROOST_PP_IIF(p(21), 21, 22)
#                            define ROOST_PP_NODE_23(p) ROOST_PP_IIF(p(23), 23, 24)
#                    define ROOST_PP_NODE_28(p) ROOST_PP_IIF(p(28), ROOST_PP_NODE_26, ROOST_PP_NODE_30)
#                        define ROOST_PP_NODE_26(p) ROOST_PP_IIF(p(26), ROOST_PP_NODE_25, ROOST_PP_NODE_27)
#                            define ROOST_PP_NODE_25(p) ROOST_PP_IIF(p(25), 25, 26)
#                            define ROOST_PP_NODE_27(p) ROOST_PP_IIF(p(27), 27, 28)
#                        define ROOST_PP_NODE_30(p) ROOST_PP_IIF(p(30), ROOST_PP_NODE_29, ROOST_PP_NODE_31)
#                            define ROOST_PP_NODE_29(p) ROOST_PP_IIF(p(29), 29, 30)
#                            define ROOST_PP_NODE_31(p) ROOST_PP_IIF(p(31), 31, 32)
#            define ROOST_PP_NODE_48(p) ROOST_PP_IIF(p(48), ROOST_PP_NODE_40, ROOST_PP_NODE_56)
#                define ROOST_PP_NODE_40(p) ROOST_PP_IIF(p(40), ROOST_PP_NODE_36, ROOST_PP_NODE_44)
#                    define ROOST_PP_NODE_36(p) ROOST_PP_IIF(p(36), ROOST_PP_NODE_34, ROOST_PP_NODE_38)
#                        define ROOST_PP_NODE_34(p) ROOST_PP_IIF(p(34), ROOST_PP_NODE_33, ROOST_PP_NODE_35)
#                            define ROOST_PP_NODE_33(p) ROOST_PP_IIF(p(33), 33, 34)
#                            define ROOST_PP_NODE_35(p) ROOST_PP_IIF(p(35), 35, 36)
#                        define ROOST_PP_NODE_38(p) ROOST_PP_IIF(p(38), ROOST_PP_NODE_37, ROOST_PP_NODE_39)
#                            define ROOST_PP_NODE_37(p) ROOST_PP_IIF(p(37), 37, 38)
#                            define ROOST_PP_NODE_39(p) ROOST_PP_IIF(p(39), 39, 40)
#                    define ROOST_PP_NODE_44(p) ROOST_PP_IIF(p(44), ROOST_PP_NODE_42, ROOST_PP_NODE_46)
#                        define ROOST_PP_NODE_42(p) ROOST_PP_IIF(p(42), ROOST_PP_NODE_41, ROOST_PP_NODE_43)
#                            define ROOST_PP_NODE_41(p) ROOST_PP_IIF(p(41), 41, 42)
#                            define ROOST_PP_NODE_43(p) ROOST_PP_IIF(p(43), 43, 44)
#                        define ROOST_PP_NODE_46(p) ROOST_PP_IIF(p(46), ROOST_PP_NODE_45, ROOST_PP_NODE_47)
#                            define ROOST_PP_NODE_45(p) ROOST_PP_IIF(p(45), 45, 46)
#                            define ROOST_PP_NODE_47(p) ROOST_PP_IIF(p(47), 47, 48)
#                define ROOST_PP_NODE_56(p) ROOST_PP_IIF(p(56), ROOST_PP_NODE_52, ROOST_PP_NODE_60)
#                    define ROOST_PP_NODE_52(p) ROOST_PP_IIF(p(52), ROOST_PP_NODE_50, ROOST_PP_NODE_54)
#                        define ROOST_PP_NODE_50(p) ROOST_PP_IIF(p(50), ROOST_PP_NODE_49, ROOST_PP_NODE_51)
#                            define ROOST_PP_NODE_49(p) ROOST_PP_IIF(p(49), 49, 50)
#                            define ROOST_PP_NODE_51(p) ROOST_PP_IIF(p(51), 51, 52)
#                        define ROOST_PP_NODE_54(p) ROOST_PP_IIF(p(54), ROOST_PP_NODE_53, ROOST_PP_NODE_55)
#                            define ROOST_PP_NODE_53(p) ROOST_PP_IIF(p(53), 53, 54)
#                            define ROOST_PP_NODE_55(p) ROOST_PP_IIF(p(55), 55, 56)
#                    define ROOST_PP_NODE_60(p) ROOST_PP_IIF(p(60), ROOST_PP_NODE_58, ROOST_PP_NODE_62)
#                        define ROOST_PP_NODE_58(p) ROOST_PP_IIF(p(58), ROOST_PP_NODE_57, ROOST_PP_NODE_59)
#                            define ROOST_PP_NODE_57(p) ROOST_PP_IIF(p(57), 57, 58)
#                            define ROOST_PP_NODE_59(p) ROOST_PP_IIF(p(59), 59, 60)
#                        define ROOST_PP_NODE_62(p) ROOST_PP_IIF(p(62), ROOST_PP_NODE_61, ROOST_PP_NODE_63)
#                            define ROOST_PP_NODE_61(p) ROOST_PP_IIF(p(61), 61, 62)
#                            define ROOST_PP_NODE_63(p) ROOST_PP_IIF(p(63), 63, 64)
#        define ROOST_PP_NODE_96(p) ROOST_PP_IIF(p(96), ROOST_PP_NODE_80, ROOST_PP_NODE_112)
#            define ROOST_PP_NODE_80(p) ROOST_PP_IIF(p(80), ROOST_PP_NODE_72, ROOST_PP_NODE_88)
#                define ROOST_PP_NODE_72(p) ROOST_PP_IIF(p(72), ROOST_PP_NODE_68, ROOST_PP_NODE_76)
#                    define ROOST_PP_NODE_68(p) ROOST_PP_IIF(p(68), ROOST_PP_NODE_66, ROOST_PP_NODE_70)
#                        define ROOST_PP_NODE_66(p) ROOST_PP_IIF(p(66), ROOST_PP_NODE_65, ROOST_PP_NODE_67)
#                            define ROOST_PP_NODE_65(p) ROOST_PP_IIF(p(65), 65, 66)
#                            define ROOST_PP_NODE_67(p) ROOST_PP_IIF(p(67), 67, 68)
#                        define ROOST_PP_NODE_70(p) ROOST_PP_IIF(p(70), ROOST_PP_NODE_69, ROOST_PP_NODE_71)
#                            define ROOST_PP_NODE_69(p) ROOST_PP_IIF(p(69), 69, 70)
#                            define ROOST_PP_NODE_71(p) ROOST_PP_IIF(p(71), 71, 72)
#                    define ROOST_PP_NODE_76(p) ROOST_PP_IIF(p(76), ROOST_PP_NODE_74, ROOST_PP_NODE_78)
#                        define ROOST_PP_NODE_74(p) ROOST_PP_IIF(p(74), ROOST_PP_NODE_73, ROOST_PP_NODE_75)
#                            define ROOST_PP_NODE_73(p) ROOST_PP_IIF(p(73), 73, 74)
#                            define ROOST_PP_NODE_75(p) ROOST_PP_IIF(p(75), 75, 76)
#                        define ROOST_PP_NODE_78(p) ROOST_PP_IIF(p(78), ROOST_PP_NODE_77, ROOST_PP_NODE_79)
#                            define ROOST_PP_NODE_77(p) ROOST_PP_IIF(p(77), 77, 78)
#                            define ROOST_PP_NODE_79(p) ROOST_PP_IIF(p(79), 79, 80)
#                define ROOST_PP_NODE_88(p) ROOST_PP_IIF(p(88), ROOST_PP_NODE_84, ROOST_PP_NODE_92)
#                    define ROOST_PP_NODE_84(p) ROOST_PP_IIF(p(84), ROOST_PP_NODE_82, ROOST_PP_NODE_86)
#                        define ROOST_PP_NODE_82(p) ROOST_PP_IIF(p(82), ROOST_PP_NODE_81, ROOST_PP_NODE_83)
#                            define ROOST_PP_NODE_81(p) ROOST_PP_IIF(p(81), 81, 82)
#                            define ROOST_PP_NODE_83(p) ROOST_PP_IIF(p(83), 83, 84)
#                        define ROOST_PP_NODE_86(p) ROOST_PP_IIF(p(86), ROOST_PP_NODE_85, ROOST_PP_NODE_87)
#                            define ROOST_PP_NODE_85(p) ROOST_PP_IIF(p(85), 85, 86)
#                            define ROOST_PP_NODE_87(p) ROOST_PP_IIF(p(87), 87, 88)
#                    define ROOST_PP_NODE_92(p) ROOST_PP_IIF(p(92), ROOST_PP_NODE_90, ROOST_PP_NODE_94)
#                        define ROOST_PP_NODE_90(p) ROOST_PP_IIF(p(90), ROOST_PP_NODE_89, ROOST_PP_NODE_91)
#                            define ROOST_PP_NODE_89(p) ROOST_PP_IIF(p(89), 89, 90)
#                            define ROOST_PP_NODE_91(p) ROOST_PP_IIF(p(91), 91, 92)
#                        define ROOST_PP_NODE_94(p) ROOST_PP_IIF(p(94), ROOST_PP_NODE_93, ROOST_PP_NODE_95)
#                            define ROOST_PP_NODE_93(p) ROOST_PP_IIF(p(93), 93, 94)
#                            define ROOST_PP_NODE_95(p) ROOST_PP_IIF(p(95), 95, 96)
#            define ROOST_PP_NODE_112(p) ROOST_PP_IIF(p(112), ROOST_PP_NODE_104, ROOST_PP_NODE_120)
#                define ROOST_PP_NODE_104(p) ROOST_PP_IIF(p(104), ROOST_PP_NODE_100, ROOST_PP_NODE_108)
#                    define ROOST_PP_NODE_100(p) ROOST_PP_IIF(p(100), ROOST_PP_NODE_98, ROOST_PP_NODE_102)
#                        define ROOST_PP_NODE_98(p) ROOST_PP_IIF(p(98), ROOST_PP_NODE_97, ROOST_PP_NODE_99)
#                            define ROOST_PP_NODE_97(p) ROOST_PP_IIF(p(97), 97, 98)
#                            define ROOST_PP_NODE_99(p) ROOST_PP_IIF(p(99), 99, 100)
#                        define ROOST_PP_NODE_102(p) ROOST_PP_IIF(p(102), ROOST_PP_NODE_101, ROOST_PP_NODE_103)
#                            define ROOST_PP_NODE_101(p) ROOST_PP_IIF(p(101), 101, 102)
#                            define ROOST_PP_NODE_103(p) ROOST_PP_IIF(p(103), 103, 104)
#                    define ROOST_PP_NODE_108(p) ROOST_PP_IIF(p(108), ROOST_PP_NODE_106, ROOST_PP_NODE_110)
#                        define ROOST_PP_NODE_106(p) ROOST_PP_IIF(p(106), ROOST_PP_NODE_105, ROOST_PP_NODE_107)
#                            define ROOST_PP_NODE_105(p) ROOST_PP_IIF(p(105), 105, 106)
#                            define ROOST_PP_NODE_107(p) ROOST_PP_IIF(p(107), 107, 108)
#                        define ROOST_PP_NODE_110(p) ROOST_PP_IIF(p(110), ROOST_PP_NODE_109, ROOST_PP_NODE_111)
#                            define ROOST_PP_NODE_109(p) ROOST_PP_IIF(p(109), 109, 110)
#                            define ROOST_PP_NODE_111(p) ROOST_PP_IIF(p(111), 111, 112)
#                define ROOST_PP_NODE_120(p) ROOST_PP_IIF(p(120), ROOST_PP_NODE_116, ROOST_PP_NODE_124)
#                    define ROOST_PP_NODE_116(p) ROOST_PP_IIF(p(116), ROOST_PP_NODE_114, ROOST_PP_NODE_118)
#                        define ROOST_PP_NODE_114(p) ROOST_PP_IIF(p(114), ROOST_PP_NODE_113, ROOST_PP_NODE_115)
#                            define ROOST_PP_NODE_113(p) ROOST_PP_IIF(p(113), 113, 114)
#                            define ROOST_PP_NODE_115(p) ROOST_PP_IIF(p(115), 115, 116)
#                        define ROOST_PP_NODE_118(p) ROOST_PP_IIF(p(118), ROOST_PP_NODE_117, ROOST_PP_NODE_119)
#                            define ROOST_PP_NODE_117(p) ROOST_PP_IIF(p(117), 117, 118)
#                            define ROOST_PP_NODE_119(p) ROOST_PP_IIF(p(119), 119, 120)
#                    define ROOST_PP_NODE_124(p) ROOST_PP_IIF(p(124), ROOST_PP_NODE_122, ROOST_PP_NODE_126)
#                        define ROOST_PP_NODE_122(p) ROOST_PP_IIF(p(122), ROOST_PP_NODE_121, ROOST_PP_NODE_123)
#                            define ROOST_PP_NODE_121(p) ROOST_PP_IIF(p(121), 121, 122)
#                            define ROOST_PP_NODE_123(p) ROOST_PP_IIF(p(123), 123, 124)
#                        define ROOST_PP_NODE_126(p) ROOST_PP_IIF(p(126), ROOST_PP_NODE_125, ROOST_PP_NODE_127)
#                            define ROOST_PP_NODE_125(p) ROOST_PP_IIF(p(125), 125, 126)
#                            define ROOST_PP_NODE_127(p) ROOST_PP_IIF(p(127), 127, 128)
#    define ROOST_PP_NODE_192(p) ROOST_PP_IIF(p(192), ROOST_PP_NODE_160, ROOST_PP_NODE_224)
#        define ROOST_PP_NODE_160(p) ROOST_PP_IIF(p(160), ROOST_PP_NODE_144, ROOST_PP_NODE_176)
#            define ROOST_PP_NODE_144(p) ROOST_PP_IIF(p(144), ROOST_PP_NODE_136, ROOST_PP_NODE_152)
#                define ROOST_PP_NODE_136(p) ROOST_PP_IIF(p(136), ROOST_PP_NODE_132, ROOST_PP_NODE_140)
#                    define ROOST_PP_NODE_132(p) ROOST_PP_IIF(p(132), ROOST_PP_NODE_130, ROOST_PP_NODE_134)
#                        define ROOST_PP_NODE_130(p) ROOST_PP_IIF(p(130), ROOST_PP_NODE_129, ROOST_PP_NODE_131)
#                            define ROOST_PP_NODE_129(p) ROOST_PP_IIF(p(129), 129, 130)
#                            define ROOST_PP_NODE_131(p) ROOST_PP_IIF(p(131), 131, 132)
#                        define ROOST_PP_NODE_134(p) ROOST_PP_IIF(p(134), ROOST_PP_NODE_133, ROOST_PP_NODE_135)
#                            define ROOST_PP_NODE_133(p) ROOST_PP_IIF(p(133), 133, 134)
#                            define ROOST_PP_NODE_135(p) ROOST_PP_IIF(p(135), 135, 136)
#                    define ROOST_PP_NODE_140(p) ROOST_PP_IIF(p(140), ROOST_PP_NODE_138, ROOST_PP_NODE_142)
#                        define ROOST_PP_NODE_138(p) ROOST_PP_IIF(p(138), ROOST_PP_NODE_137, ROOST_PP_NODE_139)
#                            define ROOST_PP_NODE_137(p) ROOST_PP_IIF(p(137), 137, 138)
#                            define ROOST_PP_NODE_139(p) ROOST_PP_IIF(p(139), 139, 140)
#                        define ROOST_PP_NODE_142(p) ROOST_PP_IIF(p(142), ROOST_PP_NODE_141, ROOST_PP_NODE_143)
#                            define ROOST_PP_NODE_141(p) ROOST_PP_IIF(p(141), 141, 142)
#                            define ROOST_PP_NODE_143(p) ROOST_PP_IIF(p(143), 143, 144)
#                define ROOST_PP_NODE_152(p) ROOST_PP_IIF(p(152), ROOST_PP_NODE_148, ROOST_PP_NODE_156)
#                    define ROOST_PP_NODE_148(p) ROOST_PP_IIF(p(148), ROOST_PP_NODE_146, ROOST_PP_NODE_150)
#                        define ROOST_PP_NODE_146(p) ROOST_PP_IIF(p(146), ROOST_PP_NODE_145, ROOST_PP_NODE_147)
#                            define ROOST_PP_NODE_145(p) ROOST_PP_IIF(p(145), 145, 146)
#                            define ROOST_PP_NODE_147(p) ROOST_PP_IIF(p(147), 147, 148)
#                        define ROOST_PP_NODE_150(p) ROOST_PP_IIF(p(150), ROOST_PP_NODE_149, ROOST_PP_NODE_151)
#                            define ROOST_PP_NODE_149(p) ROOST_PP_IIF(p(149), 149, 150)
#                            define ROOST_PP_NODE_151(p) ROOST_PP_IIF(p(151), 151, 152)
#                    define ROOST_PP_NODE_156(p) ROOST_PP_IIF(p(156), ROOST_PP_NODE_154, ROOST_PP_NODE_158)
#                        define ROOST_PP_NODE_154(p) ROOST_PP_IIF(p(154), ROOST_PP_NODE_153, ROOST_PP_NODE_155)
#                            define ROOST_PP_NODE_153(p) ROOST_PP_IIF(p(153), 153, 154)
#                            define ROOST_PP_NODE_155(p) ROOST_PP_IIF(p(155), 155, 156)
#                        define ROOST_PP_NODE_158(p) ROOST_PP_IIF(p(158), ROOST_PP_NODE_157, ROOST_PP_NODE_159)
#                            define ROOST_PP_NODE_157(p) ROOST_PP_IIF(p(157), 157, 158)
#                            define ROOST_PP_NODE_159(p) ROOST_PP_IIF(p(159), 159, 160)
#            define ROOST_PP_NODE_176(p) ROOST_PP_IIF(p(176), ROOST_PP_NODE_168, ROOST_PP_NODE_184)
#                define ROOST_PP_NODE_168(p) ROOST_PP_IIF(p(168), ROOST_PP_NODE_164, ROOST_PP_NODE_172)
#                    define ROOST_PP_NODE_164(p) ROOST_PP_IIF(p(164), ROOST_PP_NODE_162, ROOST_PP_NODE_166)
#                        define ROOST_PP_NODE_162(p) ROOST_PP_IIF(p(162), ROOST_PP_NODE_161, ROOST_PP_NODE_163)
#                            define ROOST_PP_NODE_161(p) ROOST_PP_IIF(p(161), 161, 162)
#                            define ROOST_PP_NODE_163(p) ROOST_PP_IIF(p(163), 163, 164)
#                        define ROOST_PP_NODE_166(p) ROOST_PP_IIF(p(166), ROOST_PP_NODE_165, ROOST_PP_NODE_167)
#                            define ROOST_PP_NODE_165(p) ROOST_PP_IIF(p(165), 165, 166)
#                            define ROOST_PP_NODE_167(p) ROOST_PP_IIF(p(167), 167, 168)
#                    define ROOST_PP_NODE_172(p) ROOST_PP_IIF(p(172), ROOST_PP_NODE_170, ROOST_PP_NODE_174)
#                        define ROOST_PP_NODE_170(p) ROOST_PP_IIF(p(170), ROOST_PP_NODE_169, ROOST_PP_NODE_171)
#                            define ROOST_PP_NODE_169(p) ROOST_PP_IIF(p(169), 169, 170)
#                            define ROOST_PP_NODE_171(p) ROOST_PP_IIF(p(171), 171, 172)
#                        define ROOST_PP_NODE_174(p) ROOST_PP_IIF(p(174), ROOST_PP_NODE_173, ROOST_PP_NODE_175)
#                            define ROOST_PP_NODE_173(p) ROOST_PP_IIF(p(173), 173, 174)
#                            define ROOST_PP_NODE_175(p) ROOST_PP_IIF(p(175), 175, 176)
#                define ROOST_PP_NODE_184(p) ROOST_PP_IIF(p(184), ROOST_PP_NODE_180, ROOST_PP_NODE_188)
#                    define ROOST_PP_NODE_180(p) ROOST_PP_IIF(p(180), ROOST_PP_NODE_178, ROOST_PP_NODE_182)
#                        define ROOST_PP_NODE_178(p) ROOST_PP_IIF(p(178), ROOST_PP_NODE_177, ROOST_PP_NODE_179)
#                            define ROOST_PP_NODE_177(p) ROOST_PP_IIF(p(177), 177, 178)
#                            define ROOST_PP_NODE_179(p) ROOST_PP_IIF(p(179), 179, 180)
#                        define ROOST_PP_NODE_182(p) ROOST_PP_IIF(p(182), ROOST_PP_NODE_181, ROOST_PP_NODE_183)
#                            define ROOST_PP_NODE_181(p) ROOST_PP_IIF(p(181), 181, 182)
#                            define ROOST_PP_NODE_183(p) ROOST_PP_IIF(p(183), 183, 184)
#                    define ROOST_PP_NODE_188(p) ROOST_PP_IIF(p(188), ROOST_PP_NODE_186, ROOST_PP_NODE_190)
#                        define ROOST_PP_NODE_186(p) ROOST_PP_IIF(p(186), ROOST_PP_NODE_185, ROOST_PP_NODE_187)
#                            define ROOST_PP_NODE_185(p) ROOST_PP_IIF(p(185), 185, 186)
#                            define ROOST_PP_NODE_187(p) ROOST_PP_IIF(p(187), 187, 188)
#                        define ROOST_PP_NODE_190(p) ROOST_PP_IIF(p(190), ROOST_PP_NODE_189, ROOST_PP_NODE_191)
#                            define ROOST_PP_NODE_189(p) ROOST_PP_IIF(p(189), 189, 190)
#                            define ROOST_PP_NODE_191(p) ROOST_PP_IIF(p(191), 191, 192)
#        define ROOST_PP_NODE_224(p) ROOST_PP_IIF(p(224), ROOST_PP_NODE_208, ROOST_PP_NODE_240)
#            define ROOST_PP_NODE_208(p) ROOST_PP_IIF(p(208), ROOST_PP_NODE_200, ROOST_PP_NODE_216)
#                define ROOST_PP_NODE_200(p) ROOST_PP_IIF(p(200), ROOST_PP_NODE_196, ROOST_PP_NODE_204)
#                    define ROOST_PP_NODE_196(p) ROOST_PP_IIF(p(196), ROOST_PP_NODE_194, ROOST_PP_NODE_198)
#                        define ROOST_PP_NODE_194(p) ROOST_PP_IIF(p(194), ROOST_PP_NODE_193, ROOST_PP_NODE_195)
#                            define ROOST_PP_NODE_193(p) ROOST_PP_IIF(p(193), 193, 194)
#                            define ROOST_PP_NODE_195(p) ROOST_PP_IIF(p(195), 195, 196)
#                        define ROOST_PP_NODE_198(p) ROOST_PP_IIF(p(198), ROOST_PP_NODE_197, ROOST_PP_NODE_199)
#                            define ROOST_PP_NODE_197(p) ROOST_PP_IIF(p(197), 197, 198)
#                            define ROOST_PP_NODE_199(p) ROOST_PP_IIF(p(199), 199, 200)
#                    define ROOST_PP_NODE_204(p) ROOST_PP_IIF(p(204), ROOST_PP_NODE_202, ROOST_PP_NODE_206)
#                        define ROOST_PP_NODE_202(p) ROOST_PP_IIF(p(202), ROOST_PP_NODE_201, ROOST_PP_NODE_203)
#                            define ROOST_PP_NODE_201(p) ROOST_PP_IIF(p(201), 201, 202)
#                            define ROOST_PP_NODE_203(p) ROOST_PP_IIF(p(203), 203, 204)
#                        define ROOST_PP_NODE_206(p) ROOST_PP_IIF(p(206), ROOST_PP_NODE_205, ROOST_PP_NODE_207)
#                            define ROOST_PP_NODE_205(p) ROOST_PP_IIF(p(205), 205, 206)
#                            define ROOST_PP_NODE_207(p) ROOST_PP_IIF(p(207), 207, 208)
#                define ROOST_PP_NODE_216(p) ROOST_PP_IIF(p(216), ROOST_PP_NODE_212, ROOST_PP_NODE_220)
#                    define ROOST_PP_NODE_212(p) ROOST_PP_IIF(p(212), ROOST_PP_NODE_210, ROOST_PP_NODE_214)
#                        define ROOST_PP_NODE_210(p) ROOST_PP_IIF(p(210), ROOST_PP_NODE_209, ROOST_PP_NODE_211)
#                            define ROOST_PP_NODE_209(p) ROOST_PP_IIF(p(209), 209, 210)
#                            define ROOST_PP_NODE_211(p) ROOST_PP_IIF(p(211), 211, 212)
#                        define ROOST_PP_NODE_214(p) ROOST_PP_IIF(p(214), ROOST_PP_NODE_213, ROOST_PP_NODE_215)
#                            define ROOST_PP_NODE_213(p) ROOST_PP_IIF(p(213), 213, 214)
#                            define ROOST_PP_NODE_215(p) ROOST_PP_IIF(p(215), 215, 216)
#                    define ROOST_PP_NODE_220(p) ROOST_PP_IIF(p(220), ROOST_PP_NODE_218, ROOST_PP_NODE_222)
#                        define ROOST_PP_NODE_218(p) ROOST_PP_IIF(p(218), ROOST_PP_NODE_217, ROOST_PP_NODE_219)
#                            define ROOST_PP_NODE_217(p) ROOST_PP_IIF(p(217), 217, 218)
#                            define ROOST_PP_NODE_219(p) ROOST_PP_IIF(p(219), 219, 220)
#                        define ROOST_PP_NODE_222(p) ROOST_PP_IIF(p(222), ROOST_PP_NODE_221, ROOST_PP_NODE_223)
#                            define ROOST_PP_NODE_221(p) ROOST_PP_IIF(p(221), 221, 222)
#                            define ROOST_PP_NODE_223(p) ROOST_PP_IIF(p(223), 223, 224)
#            define ROOST_PP_NODE_240(p) ROOST_PP_IIF(p(240), ROOST_PP_NODE_232, ROOST_PP_NODE_248)
#                define ROOST_PP_NODE_232(p) ROOST_PP_IIF(p(232), ROOST_PP_NODE_228, ROOST_PP_NODE_236)
#                    define ROOST_PP_NODE_228(p) ROOST_PP_IIF(p(228), ROOST_PP_NODE_226, ROOST_PP_NODE_230)
#                        define ROOST_PP_NODE_226(p) ROOST_PP_IIF(p(226), ROOST_PP_NODE_225, ROOST_PP_NODE_227)
#                            define ROOST_PP_NODE_225(p) ROOST_PP_IIF(p(225), 225, 226)
#                            define ROOST_PP_NODE_227(p) ROOST_PP_IIF(p(227), 227, 228)
#                        define ROOST_PP_NODE_230(p) ROOST_PP_IIF(p(230), ROOST_PP_NODE_229, ROOST_PP_NODE_231)
#                            define ROOST_PP_NODE_229(p) ROOST_PP_IIF(p(229), 229, 230)
#                            define ROOST_PP_NODE_231(p) ROOST_PP_IIF(p(231), 231, 232)
#                    define ROOST_PP_NODE_236(p) ROOST_PP_IIF(p(236), ROOST_PP_NODE_234, ROOST_PP_NODE_238)
#                        define ROOST_PP_NODE_234(p) ROOST_PP_IIF(p(234), ROOST_PP_NODE_233, ROOST_PP_NODE_235)
#                            define ROOST_PP_NODE_233(p) ROOST_PP_IIF(p(233), 233, 234)
#                            define ROOST_PP_NODE_235(p) ROOST_PP_IIF(p(235), 235, 236)
#                        define ROOST_PP_NODE_238(p) ROOST_PP_IIF(p(238), ROOST_PP_NODE_237, ROOST_PP_NODE_239)
#                            define ROOST_PP_NODE_237(p) ROOST_PP_IIF(p(237), 237, 238)
#                            define ROOST_PP_NODE_239(p) ROOST_PP_IIF(p(239), 239, 240)
#                define ROOST_PP_NODE_248(p) ROOST_PP_IIF(p(248), ROOST_PP_NODE_244, ROOST_PP_NODE_252)
#                    define ROOST_PP_NODE_244(p) ROOST_PP_IIF(p(244), ROOST_PP_NODE_242, ROOST_PP_NODE_246)
#                        define ROOST_PP_NODE_242(p) ROOST_PP_IIF(p(242), ROOST_PP_NODE_241, ROOST_PP_NODE_243)
#                            define ROOST_PP_NODE_241(p) ROOST_PP_IIF(p(241), 241, 242)
#                            define ROOST_PP_NODE_243(p) ROOST_PP_IIF(p(243), 243, 244)
#                        define ROOST_PP_NODE_246(p) ROOST_PP_IIF(p(246), ROOST_PP_NODE_245, ROOST_PP_NODE_247)
#                            define ROOST_PP_NODE_245(p) ROOST_PP_IIF(p(245), 245, 246)
#                            define ROOST_PP_NODE_247(p) ROOST_PP_IIF(p(247), 247, 248)
#                    define ROOST_PP_NODE_252(p) ROOST_PP_IIF(p(252), ROOST_PP_NODE_250, ROOST_PP_NODE_254)
#                        define ROOST_PP_NODE_250(p) ROOST_PP_IIF(p(250), ROOST_PP_NODE_249, ROOST_PP_NODE_251)
#                            define ROOST_PP_NODE_249(p) ROOST_PP_IIF(p(249), 249, 250)
#                            define ROOST_PP_NODE_251(p) ROOST_PP_IIF(p(251), 251, 252)
#                        define ROOST_PP_NODE_254(p) ROOST_PP_IIF(p(254), ROOST_PP_NODE_253, ROOST_PP_NODE_255)
#                            define ROOST_PP_NODE_253(p) ROOST_PP_IIF(p(253), 253, 254)
#                            define ROOST_PP_NODE_255(p) ROOST_PP_IIF(p(255), 255, 256)
#
# endif
# endif
