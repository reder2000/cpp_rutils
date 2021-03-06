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
# ifndef ROOST_PREPROCESSOR_SEQ_SIZE_HPP
# define ROOST_PREPROCESSOR_SEQ_SIZE_HPP
#
# include <roost/preprocessor/cat.hpp>
# include <roost/preprocessor/config/config.hpp>
#
# if ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_SEQ_SIZE(seq) ROOST_PP_SEQ_SIZE_I((seq))
#    define ROOST_PP_SEQ_SIZE_I(par) ROOST_PP_SEQ_SIZE_II ## par
#    define ROOST_PP_SEQ_SIZE_II(seq) ROOST_PP_CAT(ROOST_PP_SEQ_SIZE_, ROOST_PP_SEQ_SIZE_0 ## seq)
# elif ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_EDG() || ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MSVC()
#    define ROOST_PP_SEQ_SIZE(seq) ROOST_PP_SEQ_SIZE_I(seq)
#    define ROOST_PP_SEQ_SIZE_I(seq) ROOST_PP_CAT(ROOST_PP_SEQ_SIZE_, ROOST_PP_SEQ_SIZE_0 seq)
# elif defined(__IBMC__) || defined(__IBMCPP__)
#    define ROOST_PP_SEQ_SIZE(seq) ROOST_PP_CAT(ROOST_PP_SEQ_SIZE_, ROOST_PP_CAT(ROOST_PP_SEQ_SIZE_0, seq))
# else
#    define ROOST_PP_SEQ_SIZE(seq) ROOST_PP_CAT(ROOST_PP_SEQ_SIZE_, ROOST_PP_SEQ_SIZE_0 seq)
# endif
#
# define ROOST_PP_SEQ_SIZE_0(_) ROOST_PP_SEQ_SIZE_1
# define ROOST_PP_SEQ_SIZE_1(_) ROOST_PP_SEQ_SIZE_2
# define ROOST_PP_SEQ_SIZE_2(_) ROOST_PP_SEQ_SIZE_3
# define ROOST_PP_SEQ_SIZE_3(_) ROOST_PP_SEQ_SIZE_4
# define ROOST_PP_SEQ_SIZE_4(_) ROOST_PP_SEQ_SIZE_5
# define ROOST_PP_SEQ_SIZE_5(_) ROOST_PP_SEQ_SIZE_6
# define ROOST_PP_SEQ_SIZE_6(_) ROOST_PP_SEQ_SIZE_7
# define ROOST_PP_SEQ_SIZE_7(_) ROOST_PP_SEQ_SIZE_8
# define ROOST_PP_SEQ_SIZE_8(_) ROOST_PP_SEQ_SIZE_9
# define ROOST_PP_SEQ_SIZE_9(_) ROOST_PP_SEQ_SIZE_10
# define ROOST_PP_SEQ_SIZE_10(_) ROOST_PP_SEQ_SIZE_11
# define ROOST_PP_SEQ_SIZE_11(_) ROOST_PP_SEQ_SIZE_12
# define ROOST_PP_SEQ_SIZE_12(_) ROOST_PP_SEQ_SIZE_13
# define ROOST_PP_SEQ_SIZE_13(_) ROOST_PP_SEQ_SIZE_14
# define ROOST_PP_SEQ_SIZE_14(_) ROOST_PP_SEQ_SIZE_15
# define ROOST_PP_SEQ_SIZE_15(_) ROOST_PP_SEQ_SIZE_16
# define ROOST_PP_SEQ_SIZE_16(_) ROOST_PP_SEQ_SIZE_17
# define ROOST_PP_SEQ_SIZE_17(_) ROOST_PP_SEQ_SIZE_18
# define ROOST_PP_SEQ_SIZE_18(_) ROOST_PP_SEQ_SIZE_19
# define ROOST_PP_SEQ_SIZE_19(_) ROOST_PP_SEQ_SIZE_20
# define ROOST_PP_SEQ_SIZE_20(_) ROOST_PP_SEQ_SIZE_21
# define ROOST_PP_SEQ_SIZE_21(_) ROOST_PP_SEQ_SIZE_22
# define ROOST_PP_SEQ_SIZE_22(_) ROOST_PP_SEQ_SIZE_23
# define ROOST_PP_SEQ_SIZE_23(_) ROOST_PP_SEQ_SIZE_24
# define ROOST_PP_SEQ_SIZE_24(_) ROOST_PP_SEQ_SIZE_25
# define ROOST_PP_SEQ_SIZE_25(_) ROOST_PP_SEQ_SIZE_26
# define ROOST_PP_SEQ_SIZE_26(_) ROOST_PP_SEQ_SIZE_27
# define ROOST_PP_SEQ_SIZE_27(_) ROOST_PP_SEQ_SIZE_28
# define ROOST_PP_SEQ_SIZE_28(_) ROOST_PP_SEQ_SIZE_29
# define ROOST_PP_SEQ_SIZE_29(_) ROOST_PP_SEQ_SIZE_30
# define ROOST_PP_SEQ_SIZE_30(_) ROOST_PP_SEQ_SIZE_31
# define ROOST_PP_SEQ_SIZE_31(_) ROOST_PP_SEQ_SIZE_32
# define ROOST_PP_SEQ_SIZE_32(_) ROOST_PP_SEQ_SIZE_33
# define ROOST_PP_SEQ_SIZE_33(_) ROOST_PP_SEQ_SIZE_34
# define ROOST_PP_SEQ_SIZE_34(_) ROOST_PP_SEQ_SIZE_35
# define ROOST_PP_SEQ_SIZE_35(_) ROOST_PP_SEQ_SIZE_36
# define ROOST_PP_SEQ_SIZE_36(_) ROOST_PP_SEQ_SIZE_37
# define ROOST_PP_SEQ_SIZE_37(_) ROOST_PP_SEQ_SIZE_38
# define ROOST_PP_SEQ_SIZE_38(_) ROOST_PP_SEQ_SIZE_39
# define ROOST_PP_SEQ_SIZE_39(_) ROOST_PP_SEQ_SIZE_40
# define ROOST_PP_SEQ_SIZE_40(_) ROOST_PP_SEQ_SIZE_41
# define ROOST_PP_SEQ_SIZE_41(_) ROOST_PP_SEQ_SIZE_42
# define ROOST_PP_SEQ_SIZE_42(_) ROOST_PP_SEQ_SIZE_43
# define ROOST_PP_SEQ_SIZE_43(_) ROOST_PP_SEQ_SIZE_44
# define ROOST_PP_SEQ_SIZE_44(_) ROOST_PP_SEQ_SIZE_45
# define ROOST_PP_SEQ_SIZE_45(_) ROOST_PP_SEQ_SIZE_46
# define ROOST_PP_SEQ_SIZE_46(_) ROOST_PP_SEQ_SIZE_47
# define ROOST_PP_SEQ_SIZE_47(_) ROOST_PP_SEQ_SIZE_48
# define ROOST_PP_SEQ_SIZE_48(_) ROOST_PP_SEQ_SIZE_49
# define ROOST_PP_SEQ_SIZE_49(_) ROOST_PP_SEQ_SIZE_50
# define ROOST_PP_SEQ_SIZE_50(_) ROOST_PP_SEQ_SIZE_51
# define ROOST_PP_SEQ_SIZE_51(_) ROOST_PP_SEQ_SIZE_52
# define ROOST_PP_SEQ_SIZE_52(_) ROOST_PP_SEQ_SIZE_53
# define ROOST_PP_SEQ_SIZE_53(_) ROOST_PP_SEQ_SIZE_54
# define ROOST_PP_SEQ_SIZE_54(_) ROOST_PP_SEQ_SIZE_55
# define ROOST_PP_SEQ_SIZE_55(_) ROOST_PP_SEQ_SIZE_56
# define ROOST_PP_SEQ_SIZE_56(_) ROOST_PP_SEQ_SIZE_57
# define ROOST_PP_SEQ_SIZE_57(_) ROOST_PP_SEQ_SIZE_58
# define ROOST_PP_SEQ_SIZE_58(_) ROOST_PP_SEQ_SIZE_59
# define ROOST_PP_SEQ_SIZE_59(_) ROOST_PP_SEQ_SIZE_60
# define ROOST_PP_SEQ_SIZE_60(_) ROOST_PP_SEQ_SIZE_61
# define ROOST_PP_SEQ_SIZE_61(_) ROOST_PP_SEQ_SIZE_62
# define ROOST_PP_SEQ_SIZE_62(_) ROOST_PP_SEQ_SIZE_63
# define ROOST_PP_SEQ_SIZE_63(_) ROOST_PP_SEQ_SIZE_64
# define ROOST_PP_SEQ_SIZE_64(_) ROOST_PP_SEQ_SIZE_65
# define ROOST_PP_SEQ_SIZE_65(_) ROOST_PP_SEQ_SIZE_66
# define ROOST_PP_SEQ_SIZE_66(_) ROOST_PP_SEQ_SIZE_67
# define ROOST_PP_SEQ_SIZE_67(_) ROOST_PP_SEQ_SIZE_68
# define ROOST_PP_SEQ_SIZE_68(_) ROOST_PP_SEQ_SIZE_69
# define ROOST_PP_SEQ_SIZE_69(_) ROOST_PP_SEQ_SIZE_70
# define ROOST_PP_SEQ_SIZE_70(_) ROOST_PP_SEQ_SIZE_71
# define ROOST_PP_SEQ_SIZE_71(_) ROOST_PP_SEQ_SIZE_72
# define ROOST_PP_SEQ_SIZE_72(_) ROOST_PP_SEQ_SIZE_73
# define ROOST_PP_SEQ_SIZE_73(_) ROOST_PP_SEQ_SIZE_74
# define ROOST_PP_SEQ_SIZE_74(_) ROOST_PP_SEQ_SIZE_75
# define ROOST_PP_SEQ_SIZE_75(_) ROOST_PP_SEQ_SIZE_76
# define ROOST_PP_SEQ_SIZE_76(_) ROOST_PP_SEQ_SIZE_77
# define ROOST_PP_SEQ_SIZE_77(_) ROOST_PP_SEQ_SIZE_78
# define ROOST_PP_SEQ_SIZE_78(_) ROOST_PP_SEQ_SIZE_79
# define ROOST_PP_SEQ_SIZE_79(_) ROOST_PP_SEQ_SIZE_80
# define ROOST_PP_SEQ_SIZE_80(_) ROOST_PP_SEQ_SIZE_81
# define ROOST_PP_SEQ_SIZE_81(_) ROOST_PP_SEQ_SIZE_82
# define ROOST_PP_SEQ_SIZE_82(_) ROOST_PP_SEQ_SIZE_83
# define ROOST_PP_SEQ_SIZE_83(_) ROOST_PP_SEQ_SIZE_84
# define ROOST_PP_SEQ_SIZE_84(_) ROOST_PP_SEQ_SIZE_85
# define ROOST_PP_SEQ_SIZE_85(_) ROOST_PP_SEQ_SIZE_86
# define ROOST_PP_SEQ_SIZE_86(_) ROOST_PP_SEQ_SIZE_87
# define ROOST_PP_SEQ_SIZE_87(_) ROOST_PP_SEQ_SIZE_88
# define ROOST_PP_SEQ_SIZE_88(_) ROOST_PP_SEQ_SIZE_89
# define ROOST_PP_SEQ_SIZE_89(_) ROOST_PP_SEQ_SIZE_90
# define ROOST_PP_SEQ_SIZE_90(_) ROOST_PP_SEQ_SIZE_91
# define ROOST_PP_SEQ_SIZE_91(_) ROOST_PP_SEQ_SIZE_92
# define ROOST_PP_SEQ_SIZE_92(_) ROOST_PP_SEQ_SIZE_93
# define ROOST_PP_SEQ_SIZE_93(_) ROOST_PP_SEQ_SIZE_94
# define ROOST_PP_SEQ_SIZE_94(_) ROOST_PP_SEQ_SIZE_95
# define ROOST_PP_SEQ_SIZE_95(_) ROOST_PP_SEQ_SIZE_96
# define ROOST_PP_SEQ_SIZE_96(_) ROOST_PP_SEQ_SIZE_97
# define ROOST_PP_SEQ_SIZE_97(_) ROOST_PP_SEQ_SIZE_98
# define ROOST_PP_SEQ_SIZE_98(_) ROOST_PP_SEQ_SIZE_99
# define ROOST_PP_SEQ_SIZE_99(_) ROOST_PP_SEQ_SIZE_100
# define ROOST_PP_SEQ_SIZE_100(_) ROOST_PP_SEQ_SIZE_101
# define ROOST_PP_SEQ_SIZE_101(_) ROOST_PP_SEQ_SIZE_102
# define ROOST_PP_SEQ_SIZE_102(_) ROOST_PP_SEQ_SIZE_103
# define ROOST_PP_SEQ_SIZE_103(_) ROOST_PP_SEQ_SIZE_104
# define ROOST_PP_SEQ_SIZE_104(_) ROOST_PP_SEQ_SIZE_105
# define ROOST_PP_SEQ_SIZE_105(_) ROOST_PP_SEQ_SIZE_106
# define ROOST_PP_SEQ_SIZE_106(_) ROOST_PP_SEQ_SIZE_107
# define ROOST_PP_SEQ_SIZE_107(_) ROOST_PP_SEQ_SIZE_108
# define ROOST_PP_SEQ_SIZE_108(_) ROOST_PP_SEQ_SIZE_109
# define ROOST_PP_SEQ_SIZE_109(_) ROOST_PP_SEQ_SIZE_110
# define ROOST_PP_SEQ_SIZE_110(_) ROOST_PP_SEQ_SIZE_111
# define ROOST_PP_SEQ_SIZE_111(_) ROOST_PP_SEQ_SIZE_112
# define ROOST_PP_SEQ_SIZE_112(_) ROOST_PP_SEQ_SIZE_113
# define ROOST_PP_SEQ_SIZE_113(_) ROOST_PP_SEQ_SIZE_114
# define ROOST_PP_SEQ_SIZE_114(_) ROOST_PP_SEQ_SIZE_115
# define ROOST_PP_SEQ_SIZE_115(_) ROOST_PP_SEQ_SIZE_116
# define ROOST_PP_SEQ_SIZE_116(_) ROOST_PP_SEQ_SIZE_117
# define ROOST_PP_SEQ_SIZE_117(_) ROOST_PP_SEQ_SIZE_118
# define ROOST_PP_SEQ_SIZE_118(_) ROOST_PP_SEQ_SIZE_119
# define ROOST_PP_SEQ_SIZE_119(_) ROOST_PP_SEQ_SIZE_120
# define ROOST_PP_SEQ_SIZE_120(_) ROOST_PP_SEQ_SIZE_121
# define ROOST_PP_SEQ_SIZE_121(_) ROOST_PP_SEQ_SIZE_122
# define ROOST_PP_SEQ_SIZE_122(_) ROOST_PP_SEQ_SIZE_123
# define ROOST_PP_SEQ_SIZE_123(_) ROOST_PP_SEQ_SIZE_124
# define ROOST_PP_SEQ_SIZE_124(_) ROOST_PP_SEQ_SIZE_125
# define ROOST_PP_SEQ_SIZE_125(_) ROOST_PP_SEQ_SIZE_126
# define ROOST_PP_SEQ_SIZE_126(_) ROOST_PP_SEQ_SIZE_127
# define ROOST_PP_SEQ_SIZE_127(_) ROOST_PP_SEQ_SIZE_128
# define ROOST_PP_SEQ_SIZE_128(_) ROOST_PP_SEQ_SIZE_129
# define ROOST_PP_SEQ_SIZE_129(_) ROOST_PP_SEQ_SIZE_130
# define ROOST_PP_SEQ_SIZE_130(_) ROOST_PP_SEQ_SIZE_131
# define ROOST_PP_SEQ_SIZE_131(_) ROOST_PP_SEQ_SIZE_132
# define ROOST_PP_SEQ_SIZE_132(_) ROOST_PP_SEQ_SIZE_133
# define ROOST_PP_SEQ_SIZE_133(_) ROOST_PP_SEQ_SIZE_134
# define ROOST_PP_SEQ_SIZE_134(_) ROOST_PP_SEQ_SIZE_135
# define ROOST_PP_SEQ_SIZE_135(_) ROOST_PP_SEQ_SIZE_136
# define ROOST_PP_SEQ_SIZE_136(_) ROOST_PP_SEQ_SIZE_137
# define ROOST_PP_SEQ_SIZE_137(_) ROOST_PP_SEQ_SIZE_138
# define ROOST_PP_SEQ_SIZE_138(_) ROOST_PP_SEQ_SIZE_139
# define ROOST_PP_SEQ_SIZE_139(_) ROOST_PP_SEQ_SIZE_140
# define ROOST_PP_SEQ_SIZE_140(_) ROOST_PP_SEQ_SIZE_141
# define ROOST_PP_SEQ_SIZE_141(_) ROOST_PP_SEQ_SIZE_142
# define ROOST_PP_SEQ_SIZE_142(_) ROOST_PP_SEQ_SIZE_143
# define ROOST_PP_SEQ_SIZE_143(_) ROOST_PP_SEQ_SIZE_144
# define ROOST_PP_SEQ_SIZE_144(_) ROOST_PP_SEQ_SIZE_145
# define ROOST_PP_SEQ_SIZE_145(_) ROOST_PP_SEQ_SIZE_146
# define ROOST_PP_SEQ_SIZE_146(_) ROOST_PP_SEQ_SIZE_147
# define ROOST_PP_SEQ_SIZE_147(_) ROOST_PP_SEQ_SIZE_148
# define ROOST_PP_SEQ_SIZE_148(_) ROOST_PP_SEQ_SIZE_149
# define ROOST_PP_SEQ_SIZE_149(_) ROOST_PP_SEQ_SIZE_150
# define ROOST_PP_SEQ_SIZE_150(_) ROOST_PP_SEQ_SIZE_151
# define ROOST_PP_SEQ_SIZE_151(_) ROOST_PP_SEQ_SIZE_152
# define ROOST_PP_SEQ_SIZE_152(_) ROOST_PP_SEQ_SIZE_153
# define ROOST_PP_SEQ_SIZE_153(_) ROOST_PP_SEQ_SIZE_154
# define ROOST_PP_SEQ_SIZE_154(_) ROOST_PP_SEQ_SIZE_155
# define ROOST_PP_SEQ_SIZE_155(_) ROOST_PP_SEQ_SIZE_156
# define ROOST_PP_SEQ_SIZE_156(_) ROOST_PP_SEQ_SIZE_157
# define ROOST_PP_SEQ_SIZE_157(_) ROOST_PP_SEQ_SIZE_158
# define ROOST_PP_SEQ_SIZE_158(_) ROOST_PP_SEQ_SIZE_159
# define ROOST_PP_SEQ_SIZE_159(_) ROOST_PP_SEQ_SIZE_160
# define ROOST_PP_SEQ_SIZE_160(_) ROOST_PP_SEQ_SIZE_161
# define ROOST_PP_SEQ_SIZE_161(_) ROOST_PP_SEQ_SIZE_162
# define ROOST_PP_SEQ_SIZE_162(_) ROOST_PP_SEQ_SIZE_163
# define ROOST_PP_SEQ_SIZE_163(_) ROOST_PP_SEQ_SIZE_164
# define ROOST_PP_SEQ_SIZE_164(_) ROOST_PP_SEQ_SIZE_165
# define ROOST_PP_SEQ_SIZE_165(_) ROOST_PP_SEQ_SIZE_166
# define ROOST_PP_SEQ_SIZE_166(_) ROOST_PP_SEQ_SIZE_167
# define ROOST_PP_SEQ_SIZE_167(_) ROOST_PP_SEQ_SIZE_168
# define ROOST_PP_SEQ_SIZE_168(_) ROOST_PP_SEQ_SIZE_169
# define ROOST_PP_SEQ_SIZE_169(_) ROOST_PP_SEQ_SIZE_170
# define ROOST_PP_SEQ_SIZE_170(_) ROOST_PP_SEQ_SIZE_171
# define ROOST_PP_SEQ_SIZE_171(_) ROOST_PP_SEQ_SIZE_172
# define ROOST_PP_SEQ_SIZE_172(_) ROOST_PP_SEQ_SIZE_173
# define ROOST_PP_SEQ_SIZE_173(_) ROOST_PP_SEQ_SIZE_174
# define ROOST_PP_SEQ_SIZE_174(_) ROOST_PP_SEQ_SIZE_175
# define ROOST_PP_SEQ_SIZE_175(_) ROOST_PP_SEQ_SIZE_176
# define ROOST_PP_SEQ_SIZE_176(_) ROOST_PP_SEQ_SIZE_177
# define ROOST_PP_SEQ_SIZE_177(_) ROOST_PP_SEQ_SIZE_178
# define ROOST_PP_SEQ_SIZE_178(_) ROOST_PP_SEQ_SIZE_179
# define ROOST_PP_SEQ_SIZE_179(_) ROOST_PP_SEQ_SIZE_180
# define ROOST_PP_SEQ_SIZE_180(_) ROOST_PP_SEQ_SIZE_181
# define ROOST_PP_SEQ_SIZE_181(_) ROOST_PP_SEQ_SIZE_182
# define ROOST_PP_SEQ_SIZE_182(_) ROOST_PP_SEQ_SIZE_183
# define ROOST_PP_SEQ_SIZE_183(_) ROOST_PP_SEQ_SIZE_184
# define ROOST_PP_SEQ_SIZE_184(_) ROOST_PP_SEQ_SIZE_185
# define ROOST_PP_SEQ_SIZE_185(_) ROOST_PP_SEQ_SIZE_186
# define ROOST_PP_SEQ_SIZE_186(_) ROOST_PP_SEQ_SIZE_187
# define ROOST_PP_SEQ_SIZE_187(_) ROOST_PP_SEQ_SIZE_188
# define ROOST_PP_SEQ_SIZE_188(_) ROOST_PP_SEQ_SIZE_189
# define ROOST_PP_SEQ_SIZE_189(_) ROOST_PP_SEQ_SIZE_190
# define ROOST_PP_SEQ_SIZE_190(_) ROOST_PP_SEQ_SIZE_191
# define ROOST_PP_SEQ_SIZE_191(_) ROOST_PP_SEQ_SIZE_192
# define ROOST_PP_SEQ_SIZE_192(_) ROOST_PP_SEQ_SIZE_193
# define ROOST_PP_SEQ_SIZE_193(_) ROOST_PP_SEQ_SIZE_194
# define ROOST_PP_SEQ_SIZE_194(_) ROOST_PP_SEQ_SIZE_195
# define ROOST_PP_SEQ_SIZE_195(_) ROOST_PP_SEQ_SIZE_196
# define ROOST_PP_SEQ_SIZE_196(_) ROOST_PP_SEQ_SIZE_197
# define ROOST_PP_SEQ_SIZE_197(_) ROOST_PP_SEQ_SIZE_198
# define ROOST_PP_SEQ_SIZE_198(_) ROOST_PP_SEQ_SIZE_199
# define ROOST_PP_SEQ_SIZE_199(_) ROOST_PP_SEQ_SIZE_200
# define ROOST_PP_SEQ_SIZE_200(_) ROOST_PP_SEQ_SIZE_201
# define ROOST_PP_SEQ_SIZE_201(_) ROOST_PP_SEQ_SIZE_202
# define ROOST_PP_SEQ_SIZE_202(_) ROOST_PP_SEQ_SIZE_203
# define ROOST_PP_SEQ_SIZE_203(_) ROOST_PP_SEQ_SIZE_204
# define ROOST_PP_SEQ_SIZE_204(_) ROOST_PP_SEQ_SIZE_205
# define ROOST_PP_SEQ_SIZE_205(_) ROOST_PP_SEQ_SIZE_206
# define ROOST_PP_SEQ_SIZE_206(_) ROOST_PP_SEQ_SIZE_207
# define ROOST_PP_SEQ_SIZE_207(_) ROOST_PP_SEQ_SIZE_208
# define ROOST_PP_SEQ_SIZE_208(_) ROOST_PP_SEQ_SIZE_209
# define ROOST_PP_SEQ_SIZE_209(_) ROOST_PP_SEQ_SIZE_210
# define ROOST_PP_SEQ_SIZE_210(_) ROOST_PP_SEQ_SIZE_211
# define ROOST_PP_SEQ_SIZE_211(_) ROOST_PP_SEQ_SIZE_212
# define ROOST_PP_SEQ_SIZE_212(_) ROOST_PP_SEQ_SIZE_213
# define ROOST_PP_SEQ_SIZE_213(_) ROOST_PP_SEQ_SIZE_214
# define ROOST_PP_SEQ_SIZE_214(_) ROOST_PP_SEQ_SIZE_215
# define ROOST_PP_SEQ_SIZE_215(_) ROOST_PP_SEQ_SIZE_216
# define ROOST_PP_SEQ_SIZE_216(_) ROOST_PP_SEQ_SIZE_217
# define ROOST_PP_SEQ_SIZE_217(_) ROOST_PP_SEQ_SIZE_218
# define ROOST_PP_SEQ_SIZE_218(_) ROOST_PP_SEQ_SIZE_219
# define ROOST_PP_SEQ_SIZE_219(_) ROOST_PP_SEQ_SIZE_220
# define ROOST_PP_SEQ_SIZE_220(_) ROOST_PP_SEQ_SIZE_221
# define ROOST_PP_SEQ_SIZE_221(_) ROOST_PP_SEQ_SIZE_222
# define ROOST_PP_SEQ_SIZE_222(_) ROOST_PP_SEQ_SIZE_223
# define ROOST_PP_SEQ_SIZE_223(_) ROOST_PP_SEQ_SIZE_224
# define ROOST_PP_SEQ_SIZE_224(_) ROOST_PP_SEQ_SIZE_225
# define ROOST_PP_SEQ_SIZE_225(_) ROOST_PP_SEQ_SIZE_226
# define ROOST_PP_SEQ_SIZE_226(_) ROOST_PP_SEQ_SIZE_227
# define ROOST_PP_SEQ_SIZE_227(_) ROOST_PP_SEQ_SIZE_228
# define ROOST_PP_SEQ_SIZE_228(_) ROOST_PP_SEQ_SIZE_229
# define ROOST_PP_SEQ_SIZE_229(_) ROOST_PP_SEQ_SIZE_230
# define ROOST_PP_SEQ_SIZE_230(_) ROOST_PP_SEQ_SIZE_231
# define ROOST_PP_SEQ_SIZE_231(_) ROOST_PP_SEQ_SIZE_232
# define ROOST_PP_SEQ_SIZE_232(_) ROOST_PP_SEQ_SIZE_233
# define ROOST_PP_SEQ_SIZE_233(_) ROOST_PP_SEQ_SIZE_234
# define ROOST_PP_SEQ_SIZE_234(_) ROOST_PP_SEQ_SIZE_235
# define ROOST_PP_SEQ_SIZE_235(_) ROOST_PP_SEQ_SIZE_236
# define ROOST_PP_SEQ_SIZE_236(_) ROOST_PP_SEQ_SIZE_237
# define ROOST_PP_SEQ_SIZE_237(_) ROOST_PP_SEQ_SIZE_238
# define ROOST_PP_SEQ_SIZE_238(_) ROOST_PP_SEQ_SIZE_239
# define ROOST_PP_SEQ_SIZE_239(_) ROOST_PP_SEQ_SIZE_240
# define ROOST_PP_SEQ_SIZE_240(_) ROOST_PP_SEQ_SIZE_241
# define ROOST_PP_SEQ_SIZE_241(_) ROOST_PP_SEQ_SIZE_242
# define ROOST_PP_SEQ_SIZE_242(_) ROOST_PP_SEQ_SIZE_243
# define ROOST_PP_SEQ_SIZE_243(_) ROOST_PP_SEQ_SIZE_244
# define ROOST_PP_SEQ_SIZE_244(_) ROOST_PP_SEQ_SIZE_245
# define ROOST_PP_SEQ_SIZE_245(_) ROOST_PP_SEQ_SIZE_246
# define ROOST_PP_SEQ_SIZE_246(_) ROOST_PP_SEQ_SIZE_247
# define ROOST_PP_SEQ_SIZE_247(_) ROOST_PP_SEQ_SIZE_248
# define ROOST_PP_SEQ_SIZE_248(_) ROOST_PP_SEQ_SIZE_249
# define ROOST_PP_SEQ_SIZE_249(_) ROOST_PP_SEQ_SIZE_250
# define ROOST_PP_SEQ_SIZE_250(_) ROOST_PP_SEQ_SIZE_251
# define ROOST_PP_SEQ_SIZE_251(_) ROOST_PP_SEQ_SIZE_252
# define ROOST_PP_SEQ_SIZE_252(_) ROOST_PP_SEQ_SIZE_253
# define ROOST_PP_SEQ_SIZE_253(_) ROOST_PP_SEQ_SIZE_254
# define ROOST_PP_SEQ_SIZE_254(_) ROOST_PP_SEQ_SIZE_255
# define ROOST_PP_SEQ_SIZE_255(_) ROOST_PP_SEQ_SIZE_256
# define ROOST_PP_SEQ_SIZE_256(_) ROOST_PP_SEQ_SIZE_257
#
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_0 0
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_1 1
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_2 2
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_3 3
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_4 4
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_5 5
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_6 6
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_7 7
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_8 8
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_9 9
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_10 10
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_11 11
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_12 12
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_13 13
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_14 14
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_15 15
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_16 16
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_17 17
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_18 18
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_19 19
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_20 20
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_21 21
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_22 22
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_23 23
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_24 24
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_25 25
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_26 26
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_27 27
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_28 28
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_29 29
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_30 30
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_31 31
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_32 32
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_33 33
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_34 34
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_35 35
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_36 36
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_37 37
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_38 38
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_39 39
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_40 40
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_41 41
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_42 42
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_43 43
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_44 44
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_45 45
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_46 46
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_47 47
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_48 48
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_49 49
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_50 50
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_51 51
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_52 52
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_53 53
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_54 54
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_55 55
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_56 56
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_57 57
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_58 58
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_59 59
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_60 60
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_61 61
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_62 62
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_63 63
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_64 64
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_65 65
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_66 66
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_67 67
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_68 68
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_69 69
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_70 70
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_71 71
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_72 72
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_73 73
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_74 74
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_75 75
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_76 76
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_77 77
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_78 78
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_79 79
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_80 80
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_81 81
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_82 82
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_83 83
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_84 84
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_85 85
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_86 86
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_87 87
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_88 88
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_89 89
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_90 90
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_91 91
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_92 92
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_93 93
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_94 94
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_95 95
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_96 96
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_97 97
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_98 98
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_99 99
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_100 100
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_101 101
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_102 102
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_103 103
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_104 104
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_105 105
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_106 106
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_107 107
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_108 108
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_109 109
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_110 110
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_111 111
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_112 112
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_113 113
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_114 114
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_115 115
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_116 116
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_117 117
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_118 118
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_119 119
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_120 120
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_121 121
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_122 122
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_123 123
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_124 124
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_125 125
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_126 126
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_127 127
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_128 128
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_129 129
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_130 130
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_131 131
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_132 132
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_133 133
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_134 134
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_135 135
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_136 136
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_137 137
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_138 138
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_139 139
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_140 140
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_141 141
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_142 142
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_143 143
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_144 144
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_145 145
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_146 146
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_147 147
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_148 148
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_149 149
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_150 150
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_151 151
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_152 152
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_153 153
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_154 154
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_155 155
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_156 156
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_157 157
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_158 158
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_159 159
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_160 160
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_161 161
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_162 162
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_163 163
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_164 164
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_165 165
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_166 166
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_167 167
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_168 168
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_169 169
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_170 170
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_171 171
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_172 172
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_173 173
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_174 174
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_175 175
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_176 176
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_177 177
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_178 178
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_179 179
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_180 180
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_181 181
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_182 182
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_183 183
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_184 184
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_185 185
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_186 186
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_187 187
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_188 188
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_189 189
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_190 190
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_191 191
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_192 192
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_193 193
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_194 194
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_195 195
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_196 196
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_197 197
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_198 198
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_199 199
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_200 200
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_201 201
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_202 202
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_203 203
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_204 204
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_205 205
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_206 206
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_207 207
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_208 208
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_209 209
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_210 210
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_211 211
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_212 212
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_213 213
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_214 214
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_215 215
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_216 216
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_217 217
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_218 218
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_219 219
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_220 220
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_221 221
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_222 222
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_223 223
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_224 224
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_225 225
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_226 226
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_227 227
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_228 228
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_229 229
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_230 230
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_231 231
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_232 232
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_233 233
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_234 234
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_235 235
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_236 236
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_237 237
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_238 238
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_239 239
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_240 240
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_241 241
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_242 242
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_243 243
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_244 244
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_245 245
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_246 246
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_247 247
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_248 248
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_249 249
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_250 250
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_251 251
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_252 252
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_253 253
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_254 254
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_255 255
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_256 256
# define ROOST_PP_SEQ_SIZE_ROOST_PP_SEQ_SIZE_257 257
#
# endif
