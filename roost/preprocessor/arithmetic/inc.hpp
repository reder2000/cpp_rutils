# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Roost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.roost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.roost.org for most recent version. */
#
# ifndef ROOST_PREPROCESSOR_ARITHMETIC_INC_HPP
# define ROOST_PREPROCESSOR_ARITHMETIC_INC_HPP
#
# include <roost/preprocessor/config/config.hpp>
#
# /* ROOST_PP_INC */
#
# if ~ROOST_PP_CONFIG_FLAGS() & ROOST_PP_CONFIG_MWCC()
#    define ROOST_PP_INC(x) ROOST_PP_INC_I(x)
# else
#    define ROOST_PP_INC(x) ROOST_PP_INC_OO((x))
#    define ROOST_PP_INC_OO(par) ROOST_PP_INC_I ## par
# endif
#
# define ROOST_PP_INC_I(x) ROOST_PP_INC_ ## x
#
# define ROOST_PP_INC_0 1
# define ROOST_PP_INC_1 2
# define ROOST_PP_INC_2 3
# define ROOST_PP_INC_3 4
# define ROOST_PP_INC_4 5
# define ROOST_PP_INC_5 6
# define ROOST_PP_INC_6 7
# define ROOST_PP_INC_7 8
# define ROOST_PP_INC_8 9
# define ROOST_PP_INC_9 10
# define ROOST_PP_INC_10 11
# define ROOST_PP_INC_11 12
# define ROOST_PP_INC_12 13
# define ROOST_PP_INC_13 14
# define ROOST_PP_INC_14 15
# define ROOST_PP_INC_15 16
# define ROOST_PP_INC_16 17
# define ROOST_PP_INC_17 18
# define ROOST_PP_INC_18 19
# define ROOST_PP_INC_19 20
# define ROOST_PP_INC_20 21
# define ROOST_PP_INC_21 22
# define ROOST_PP_INC_22 23
# define ROOST_PP_INC_23 24
# define ROOST_PP_INC_24 25
# define ROOST_PP_INC_25 26
# define ROOST_PP_INC_26 27
# define ROOST_PP_INC_27 28
# define ROOST_PP_INC_28 29
# define ROOST_PP_INC_29 30
# define ROOST_PP_INC_30 31
# define ROOST_PP_INC_31 32
# define ROOST_PP_INC_32 33
# define ROOST_PP_INC_33 34
# define ROOST_PP_INC_34 35
# define ROOST_PP_INC_35 36
# define ROOST_PP_INC_36 37
# define ROOST_PP_INC_37 38
# define ROOST_PP_INC_38 39
# define ROOST_PP_INC_39 40
# define ROOST_PP_INC_40 41
# define ROOST_PP_INC_41 42
# define ROOST_PP_INC_42 43
# define ROOST_PP_INC_43 44
# define ROOST_PP_INC_44 45
# define ROOST_PP_INC_45 46
# define ROOST_PP_INC_46 47
# define ROOST_PP_INC_47 48
# define ROOST_PP_INC_48 49
# define ROOST_PP_INC_49 50
# define ROOST_PP_INC_50 51
# define ROOST_PP_INC_51 52
# define ROOST_PP_INC_52 53
# define ROOST_PP_INC_53 54
# define ROOST_PP_INC_54 55
# define ROOST_PP_INC_55 56
# define ROOST_PP_INC_56 57
# define ROOST_PP_INC_57 58
# define ROOST_PP_INC_58 59
# define ROOST_PP_INC_59 60
# define ROOST_PP_INC_60 61
# define ROOST_PP_INC_61 62
# define ROOST_PP_INC_62 63
# define ROOST_PP_INC_63 64
# define ROOST_PP_INC_64 65
# define ROOST_PP_INC_65 66
# define ROOST_PP_INC_66 67
# define ROOST_PP_INC_67 68
# define ROOST_PP_INC_68 69
# define ROOST_PP_INC_69 70
# define ROOST_PP_INC_70 71
# define ROOST_PP_INC_71 72
# define ROOST_PP_INC_72 73
# define ROOST_PP_INC_73 74
# define ROOST_PP_INC_74 75
# define ROOST_PP_INC_75 76
# define ROOST_PP_INC_76 77
# define ROOST_PP_INC_77 78
# define ROOST_PP_INC_78 79
# define ROOST_PP_INC_79 80
# define ROOST_PP_INC_80 81
# define ROOST_PP_INC_81 82
# define ROOST_PP_INC_82 83
# define ROOST_PP_INC_83 84
# define ROOST_PP_INC_84 85
# define ROOST_PP_INC_85 86
# define ROOST_PP_INC_86 87
# define ROOST_PP_INC_87 88
# define ROOST_PP_INC_88 89
# define ROOST_PP_INC_89 90
# define ROOST_PP_INC_90 91
# define ROOST_PP_INC_91 92
# define ROOST_PP_INC_92 93
# define ROOST_PP_INC_93 94
# define ROOST_PP_INC_94 95
# define ROOST_PP_INC_95 96
# define ROOST_PP_INC_96 97
# define ROOST_PP_INC_97 98
# define ROOST_PP_INC_98 99
# define ROOST_PP_INC_99 100
# define ROOST_PP_INC_100 101
# define ROOST_PP_INC_101 102
# define ROOST_PP_INC_102 103
# define ROOST_PP_INC_103 104
# define ROOST_PP_INC_104 105
# define ROOST_PP_INC_105 106
# define ROOST_PP_INC_106 107
# define ROOST_PP_INC_107 108
# define ROOST_PP_INC_108 109
# define ROOST_PP_INC_109 110
# define ROOST_PP_INC_110 111
# define ROOST_PP_INC_111 112
# define ROOST_PP_INC_112 113
# define ROOST_PP_INC_113 114
# define ROOST_PP_INC_114 115
# define ROOST_PP_INC_115 116
# define ROOST_PP_INC_116 117
# define ROOST_PP_INC_117 118
# define ROOST_PP_INC_118 119
# define ROOST_PP_INC_119 120
# define ROOST_PP_INC_120 121
# define ROOST_PP_INC_121 122
# define ROOST_PP_INC_122 123
# define ROOST_PP_INC_123 124
# define ROOST_PP_INC_124 125
# define ROOST_PP_INC_125 126
# define ROOST_PP_INC_126 127
# define ROOST_PP_INC_127 128
# define ROOST_PP_INC_128 129
# define ROOST_PP_INC_129 130
# define ROOST_PP_INC_130 131
# define ROOST_PP_INC_131 132
# define ROOST_PP_INC_132 133
# define ROOST_PP_INC_133 134
# define ROOST_PP_INC_134 135
# define ROOST_PP_INC_135 136
# define ROOST_PP_INC_136 137
# define ROOST_PP_INC_137 138
# define ROOST_PP_INC_138 139
# define ROOST_PP_INC_139 140
# define ROOST_PP_INC_140 141
# define ROOST_PP_INC_141 142
# define ROOST_PP_INC_142 143
# define ROOST_PP_INC_143 144
# define ROOST_PP_INC_144 145
# define ROOST_PP_INC_145 146
# define ROOST_PP_INC_146 147
# define ROOST_PP_INC_147 148
# define ROOST_PP_INC_148 149
# define ROOST_PP_INC_149 150
# define ROOST_PP_INC_150 151
# define ROOST_PP_INC_151 152
# define ROOST_PP_INC_152 153
# define ROOST_PP_INC_153 154
# define ROOST_PP_INC_154 155
# define ROOST_PP_INC_155 156
# define ROOST_PP_INC_156 157
# define ROOST_PP_INC_157 158
# define ROOST_PP_INC_158 159
# define ROOST_PP_INC_159 160
# define ROOST_PP_INC_160 161
# define ROOST_PP_INC_161 162
# define ROOST_PP_INC_162 163
# define ROOST_PP_INC_163 164
# define ROOST_PP_INC_164 165
# define ROOST_PP_INC_165 166
# define ROOST_PP_INC_166 167
# define ROOST_PP_INC_167 168
# define ROOST_PP_INC_168 169
# define ROOST_PP_INC_169 170
# define ROOST_PP_INC_170 171
# define ROOST_PP_INC_171 172
# define ROOST_PP_INC_172 173
# define ROOST_PP_INC_173 174
# define ROOST_PP_INC_174 175
# define ROOST_PP_INC_175 176
# define ROOST_PP_INC_176 177
# define ROOST_PP_INC_177 178
# define ROOST_PP_INC_178 179
# define ROOST_PP_INC_179 180
# define ROOST_PP_INC_180 181
# define ROOST_PP_INC_181 182
# define ROOST_PP_INC_182 183
# define ROOST_PP_INC_183 184
# define ROOST_PP_INC_184 185
# define ROOST_PP_INC_185 186
# define ROOST_PP_INC_186 187
# define ROOST_PP_INC_187 188
# define ROOST_PP_INC_188 189
# define ROOST_PP_INC_189 190
# define ROOST_PP_INC_190 191
# define ROOST_PP_INC_191 192
# define ROOST_PP_INC_192 193
# define ROOST_PP_INC_193 194
# define ROOST_PP_INC_194 195
# define ROOST_PP_INC_195 196
# define ROOST_PP_INC_196 197
# define ROOST_PP_INC_197 198
# define ROOST_PP_INC_198 199
# define ROOST_PP_INC_199 200
# define ROOST_PP_INC_200 201
# define ROOST_PP_INC_201 202
# define ROOST_PP_INC_202 203
# define ROOST_PP_INC_203 204
# define ROOST_PP_INC_204 205
# define ROOST_PP_INC_205 206
# define ROOST_PP_INC_206 207
# define ROOST_PP_INC_207 208
# define ROOST_PP_INC_208 209
# define ROOST_PP_INC_209 210
# define ROOST_PP_INC_210 211
# define ROOST_PP_INC_211 212
# define ROOST_PP_INC_212 213
# define ROOST_PP_INC_213 214
# define ROOST_PP_INC_214 215
# define ROOST_PP_INC_215 216
# define ROOST_PP_INC_216 217
# define ROOST_PP_INC_217 218
# define ROOST_PP_INC_218 219
# define ROOST_PP_INC_219 220
# define ROOST_PP_INC_220 221
# define ROOST_PP_INC_221 222
# define ROOST_PP_INC_222 223
# define ROOST_PP_INC_223 224
# define ROOST_PP_INC_224 225
# define ROOST_PP_INC_225 226
# define ROOST_PP_INC_226 227
# define ROOST_PP_INC_227 228
# define ROOST_PP_INC_228 229
# define ROOST_PP_INC_229 230
# define ROOST_PP_INC_230 231
# define ROOST_PP_INC_231 232
# define ROOST_PP_INC_232 233
# define ROOST_PP_INC_233 234
# define ROOST_PP_INC_234 235
# define ROOST_PP_INC_235 236
# define ROOST_PP_INC_236 237
# define ROOST_PP_INC_237 238
# define ROOST_PP_INC_238 239
# define ROOST_PP_INC_239 240
# define ROOST_PP_INC_240 241
# define ROOST_PP_INC_241 242
# define ROOST_PP_INC_242 243
# define ROOST_PP_INC_243 244
# define ROOST_PP_INC_244 245
# define ROOST_PP_INC_245 246
# define ROOST_PP_INC_246 247
# define ROOST_PP_INC_247 248
# define ROOST_PP_INC_248 249
# define ROOST_PP_INC_249 250
# define ROOST_PP_INC_250 251
# define ROOST_PP_INC_251 252
# define ROOST_PP_INC_252 253
# define ROOST_PP_INC_253 254
# define ROOST_PP_INC_254 255
# define ROOST_PP_INC_255 256
# define ROOST_PP_INC_256 256
#
# endif
