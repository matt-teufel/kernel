extern irq_dispatch


glue: 
    push rax
    push rcx
    push rdx
    push rsi
    push r8
    push r9
    push r10
    push r11
    call irq_dispatch 
    pop r11 
    pop r10
    pop r9
    pop r8
    pop rsi
    pop rdx
    pop rcx
    pop rax
    pop rsi
    pop rdi
    add rsp, 8;
    iretq 

section .text
	global irq_entry_0
	global irq_entry_1
	global irq_entry_2
	global irq_entry_3
	global irq_entry_4
	global irq_entry_5
	global irq_entry_6
	global irq_entry_7
	global irq_entry_8
	global irq_entry_9
	global irq_entry_10
	global irq_entry_11
	global irq_entry_12
	global irq_entry_13
	global irq_entry_14
	global irq_entry_15
	global irq_entry_16
	global irq_entry_17
	global irq_entry_18
	global irq_entry_19
	global irq_entry_20
	global irq_entry_21
	global irq_entry_22
	global irq_entry_23
	global irq_entry_24
	global irq_entry_25
	global irq_entry_26
	global irq_entry_27
	global irq_entry_28
	global irq_entry_29
	global irq_entry_30
	global irq_entry_31
	global irq_entry_32
	global irq_entry_33
	global irq_entry_34
	global irq_entry_35
	global irq_entry_36
	global irq_entry_37
	global irq_entry_38
	global irq_entry_39
	global irq_entry_40
	global irq_entry_41
	global irq_entry_42
	global irq_entry_43
	global irq_entry_44
	global irq_entry_45
	global irq_entry_46
	global irq_entry_47
	global irq_entry_48
	global irq_entry_49
	global irq_entry_50
	global irq_entry_51
	global irq_entry_52
	global irq_entry_53
	global irq_entry_54
	global irq_entry_55
	global irq_entry_56
	global irq_entry_57
	global irq_entry_58
	global irq_entry_59
	global irq_entry_60
	global irq_entry_61
	global irq_entry_62
	global irq_entry_63
	global irq_entry_64
	global irq_entry_65
	global irq_entry_66
	global irq_entry_67
	global irq_entry_68
	global irq_entry_69
	global irq_entry_70
	global irq_entry_71
	global irq_entry_72
	global irq_entry_73
	global irq_entry_74
	global irq_entry_75
	global irq_entry_76
	global irq_entry_77
	global irq_entry_78
	global irq_entry_79
	global irq_entry_80
	global irq_entry_81
	global irq_entry_82
	global irq_entry_83
	global irq_entry_84
	global irq_entry_85
	global irq_entry_86
	global irq_entry_87
	global irq_entry_88
	global irq_entry_89
	global irq_entry_90
	global irq_entry_91
	global irq_entry_92
	global irq_entry_93
	global irq_entry_94
	global irq_entry_95
	global irq_entry_96
	global irq_entry_97
	global irq_entry_98
	global irq_entry_99
	global irq_entry_100
	global irq_entry_101
	global irq_entry_102
	global irq_entry_103
	global irq_entry_104
	global irq_entry_105
	global irq_entry_106
	global irq_entry_107
	global irq_entry_108
	global irq_entry_109
	global irq_entry_110
	global irq_entry_111
	global irq_entry_112
	global irq_entry_113
	global irq_entry_114
	global irq_entry_115
	global irq_entry_116
	global irq_entry_117
	global irq_entry_118
	global irq_entry_119
	global irq_entry_120
	global irq_entry_121
	global irq_entry_122
	global irq_entry_123
	global irq_entry_124
	global irq_entry_125
	global irq_entry_126
	global irq_entry_127
	global irq_entry_128
	global irq_entry_129
	global irq_entry_130
	global irq_entry_131
	global irq_entry_132
	global irq_entry_133
	global irq_entry_134
	global irq_entry_135
	global irq_entry_136
	global irq_entry_137
	global irq_entry_138
	global irq_entry_139
	global irq_entry_140
	global irq_entry_141
	global irq_entry_142
	global irq_entry_143
	global irq_entry_144
	global irq_entry_145
	global irq_entry_146
	global irq_entry_147
	global irq_entry_148
	global irq_entry_149
	global irq_entry_150
	global irq_entry_151
	global irq_entry_152
	global irq_entry_153
	global irq_entry_154
	global irq_entry_155
	global irq_entry_156
	global irq_entry_157
	global irq_entry_158
	global irq_entry_159
	global irq_entry_160
	global irq_entry_161
	global irq_entry_162
	global irq_entry_163
	global irq_entry_164
	global irq_entry_165
	global irq_entry_166
	global irq_entry_167
	global irq_entry_168
	global irq_entry_169
	global irq_entry_170
	global irq_entry_171
	global irq_entry_172
	global irq_entry_173
	global irq_entry_174
	global irq_entry_175
	global irq_entry_176
	global irq_entry_177
	global irq_entry_178
	global irq_entry_179
	global irq_entry_180
	global irq_entry_181
	global irq_entry_182
	global irq_entry_183
	global irq_entry_184
	global irq_entry_185
	global irq_entry_186
	global irq_entry_187
	global irq_entry_188
	global irq_entry_189
	global irq_entry_190
	global irq_entry_191
	global irq_entry_192
	global irq_entry_193
	global irq_entry_194
	global irq_entry_195
	global irq_entry_196
	global irq_entry_197
	global irq_entry_198
	global irq_entry_199
	global irq_entry_200
	global irq_entry_201
	global irq_entry_202
	global irq_entry_203
	global irq_entry_204
	global irq_entry_205
	global irq_entry_206
	global irq_entry_207
	global irq_entry_208
	global irq_entry_209
	global irq_entry_210
	global irq_entry_211
	global irq_entry_212
	global irq_entry_213
	global irq_entry_214
	global irq_entry_215
	global irq_entry_216
	global irq_entry_217
	global irq_entry_218
	global irq_entry_219
	global irq_entry_220
	global irq_entry_221
	global irq_entry_222
	global irq_entry_223
	global irq_entry_224
	global irq_entry_225
	global irq_entry_226
	global irq_entry_227
	global irq_entry_228
	global irq_entry_229
	global irq_entry_230
	global irq_entry_231
	global irq_entry_232
	global irq_entry_233
	global irq_entry_234
	global irq_entry_235
	global irq_entry_236
	global irq_entry_237
	global irq_entry_238
	global irq_entry_239
	global irq_entry_240
	global irq_entry_241
	global irq_entry_242
	global irq_entry_243
	global irq_entry_244
	global irq_entry_245
	global irq_entry_246
	global irq_entry_247
	global irq_entry_248
	global irq_entry_249
	global irq_entry_250
	global irq_entry_251
	global irq_entry_252
	global irq_entry_253
	global irq_entry_254
	global irq_entry_255

irq_entry_0:
    push rdi
    push rdi
    push rsi
    mov rdi, 0
    mov rsi, cr2
    jmp glue 

irq_entry_1:
    push rdi
    push rdi
    push rsi
    mov rdi, 1
    mov rsi, cr2
    jmp glue 

irq_entry_2:
    push rdi
    push rdi
    push rsi
    mov rdi, 2
    mov rsi, cr2
    jmp glue 

irq_entry_3:
    push rdi
    push rdi
    push rsi
    mov rdi, 3
    mov rsi, cr2
    jmp glue 

irq_entry_4:
    push rdi
    push rdi
    push rsi
    mov rdi, 4
    mov rsi, cr2
    jmp glue 

irq_entry_5:
    push rdi
    push rdi
    push rsi
    mov rdi, 5
    mov rsi, cr2
    jmp glue 

irq_entry_6:
    push rdi
    push rdi
    push rsi
    mov rdi, 6
    mov rsi, cr2
    jmp glue 

irq_entry_7:
    push rdi
    push rdi
    push rsi
    mov rdi, 7
    mov rsi, cr2
    jmp glue 

irq_entry_8:
    push rdi
    push rsi
    mov rdi, 8
    mov rsi, cr2
    jmp glue

irq_entry_9:
    push rdi
    push rdi
    push rsi
    mov rdi, 9
    mov rsi, cr2
    jmp glue 

irq_entry_10:
    push rdi
    push rsi
    mov rdi, 10
    mov rsi, cr2
    jmp glue

irq_entry_11:
    push rdi
    push rsi
    mov rdi, 11
    mov rsi, cr2
    jmp glue

irq_entry_12:
    push rdi
    push rsi
    mov rdi, 12
    mov rsi, cr2
    jmp glue

irq_entry_13:
    push rdi
    push rsi
    mov rdi, 13
    mov rsi, cr2
    jmp glue

irq_entry_14:
    push rdi
    push rsi
    mov rdi, 14
    mov rsi, cr2
    jmp glue

irq_entry_15:
    push rdi
    push rdi
    push rsi
    mov rdi, 15
    mov rsi, cr2
    jmp glue 

irq_entry_16:
    push rdi
    push rdi
    push rsi
    mov rdi, 16
    mov rsi, cr2
    jmp glue 

irq_entry_17:
    push rdi
    push rdi
    push rsi
    mov rdi, 17
    mov rsi, cr2
    jmp glue 

irq_entry_18:
    push rdi
    push rdi
    push rsi
    mov rdi, 18
    mov rsi, cr2
    jmp glue 

irq_entry_19:
    push rdi
    push rdi
    push rsi
    mov rdi, 19
    mov rsi, cr2
    jmp glue 

irq_entry_20:
    push rdi
    push rdi
    push rsi
    mov rdi, 20
    mov rsi, cr2
    jmp glue 

irq_entry_21:
    push rdi
    push rdi
    push rsi
    mov rdi, 21
    mov rsi, cr2
    jmp glue 

irq_entry_22:
    push rdi
    push rdi
    push rsi
    mov rdi, 22
    mov rsi, cr2
    jmp glue 

irq_entry_23:
    push rdi
    push rdi
    push rsi
    mov rdi, 23
    mov rsi, cr2
    jmp glue 

irq_entry_24:
    push rdi
    push rdi
    push rsi
    mov rdi, 24
    mov rsi, cr2
    jmp glue 

irq_entry_25:
    push rdi
    push rdi
    push rsi
    mov rdi, 25
    mov rsi, cr2
    jmp glue 

irq_entry_26:
    push rdi
    push rdi
    push rsi
    mov rdi, 26
    mov rsi, cr2
    jmp glue 

irq_entry_27:
    push rdi
    push rdi
    push rsi
    mov rdi, 27
    mov rsi, cr2
    jmp glue 

irq_entry_28:
    push rdi
    push rdi
    push rsi
    mov rdi, 28
    mov rsi, cr2
    jmp glue 

irq_entry_29:
    push rdi
    push rdi
    push rsi
    mov rdi, 29
    mov rsi, cr2
    jmp glue 

irq_entry_30:
    push rdi
    push rdi
    push rsi
    mov rdi, 30
    mov rsi, cr2
    jmp glue 

irq_entry_31:
    push rdi
    push rdi
    push rsi
    mov rdi, 31
    mov rsi, cr2
    jmp glue 

irq_entry_32:
    push rdi
    push rdi
    push rsi
    mov rdi, 32
    mov rsi, cr2
    jmp glue 

irq_entry_33:
    push rdi
    push rdi
    push rsi
    mov rdi, 33
    mov rsi, cr2
    jmp glue 

irq_entry_34:
    push rdi
    push rdi
    push rsi
    mov rdi, 34
    mov rsi, cr2
    jmp glue 

irq_entry_35:
    push rdi
    push rdi
    push rsi
    mov rdi, 35
    mov rsi, cr2
    jmp glue 

irq_entry_36:
    push rdi
    push rdi
    push rsi
    mov rdi, 36
    mov rsi, cr2
    jmp glue 

irq_entry_37:
    push rdi
    push rdi
    push rsi
    mov rdi, 37
    mov rsi, cr2
    jmp glue 

irq_entry_38:
    push rdi
    push rdi
    push rsi
    mov rdi, 38
    mov rsi, cr2
    jmp glue 

irq_entry_39:
    push rdi
    push rdi
    push rsi
    mov rdi, 39
    mov rsi, cr2
    jmp glue 

irq_entry_40:
    push rdi
    push rdi
    push rsi
    mov rdi, 40
    mov rsi, cr2
    jmp glue 

irq_entry_41:
    push rdi
    push rdi
    push rsi
    mov rdi, 41
    mov rsi, cr2
    jmp glue 

irq_entry_42:
    push rdi
    push rdi
    push rsi
    mov rdi, 42
    mov rsi, cr2
    jmp glue 

irq_entry_43:
    push rdi
    push rdi
    push rsi
    mov rdi, 43
    mov rsi, cr2
    jmp glue 

irq_entry_44:
    push rdi
    push rdi
    push rsi
    mov rdi, 44
    mov rsi, cr2
    jmp glue 

irq_entry_45:
    push rdi
    push rdi
    push rsi
    mov rdi, 45
    mov rsi, cr2
    jmp glue 

irq_entry_46:
    push rdi
    push rdi
    push rsi
    mov rdi, 46
    mov rsi, cr2
    jmp glue 

irq_entry_47:
    push rdi
    push rdi
    push rsi
    mov rdi, 47
    mov rsi, cr2
    jmp glue 

irq_entry_48:
    push rdi
    push rdi
    push rsi
    mov rdi, 48
    mov rsi, cr2
    jmp glue 

irq_entry_49:
    push rdi
    push rdi
    push rsi
    mov rdi, 49
    mov rsi, cr2
    jmp glue 

irq_entry_50:
    push rdi
    push rdi
    push rsi
    mov rdi, 50
    mov rsi, cr2
    jmp glue 

irq_entry_51:
    push rdi
    push rdi
    push rsi
    mov rdi, 51
    mov rsi, cr2
    jmp glue 

irq_entry_52:
    push rdi
    push rdi
    push rsi
    mov rdi, 52
    mov rsi, cr2
    jmp glue 

irq_entry_53:
    push rdi
    push rdi
    push rsi
    mov rdi, 53
    mov rsi, cr2
    jmp glue 

irq_entry_54:
    push rdi
    push rdi
    push rsi
    mov rdi, 54
    mov rsi, cr2
    jmp glue 

irq_entry_55:
    push rdi
    push rdi
    push rsi
    mov rdi, 55
    mov rsi, cr2
    jmp glue 

irq_entry_56:
    push rdi
    push rdi
    push rsi
    mov rdi, 56
    mov rsi, cr2
    jmp glue 

irq_entry_57:
    push rdi
    push rdi
    push rsi
    mov rdi, 57
    mov rsi, cr2
    jmp glue 

irq_entry_58:
    push rdi
    push rdi
    push rsi
    mov rdi, 58
    mov rsi, cr2
    jmp glue 

irq_entry_59:
    push rdi
    push rdi
    push rsi
    mov rdi, 59
    mov rsi, cr2
    jmp glue 

irq_entry_60:
    push rdi
    push rdi
    push rsi
    mov rdi, 60
    mov rsi, cr2
    jmp glue 

irq_entry_61:
    push rdi
    push rdi
    push rsi
    mov rdi, 61
    mov rsi, cr2
    jmp glue 

irq_entry_62:
    push rdi
    push rdi
    push rsi
    mov rdi, 62
    mov rsi, cr2
    jmp glue 

irq_entry_63:
    push rdi
    push rdi
    push rsi
    mov rdi, 63
    mov rsi, cr2
    jmp glue 

irq_entry_64:
    push rdi
    push rdi
    push rsi
    mov rdi, 64
    mov rsi, cr2
    jmp glue 

irq_entry_65:
    push rdi
    push rdi
    push rsi
    mov rdi, 65
    mov rsi, cr2
    jmp glue 

irq_entry_66:
    push rdi
    push rdi
    push rsi
    mov rdi, 66
    mov rsi, cr2
    jmp glue 

irq_entry_67:
    push rdi
    push rdi
    push rsi
    mov rdi, 67
    mov rsi, cr2
    jmp glue 

irq_entry_68:
    push rdi
    push rdi
    push rsi
    mov rdi, 68
    mov rsi, cr2
    jmp glue 

irq_entry_69:
    push rdi
    push rdi
    push rsi
    mov rdi, 69
    mov rsi, cr2
    jmp glue 

irq_entry_70:
    push rdi
    push rdi
    push rsi
    mov rdi, 70
    mov rsi, cr2
    jmp glue 

irq_entry_71:
    push rdi
    push rdi
    push rsi
    mov rdi, 71
    mov rsi, cr2
    jmp glue 

irq_entry_72:
    push rdi
    push rdi
    push rsi
    mov rdi, 72
    mov rsi, cr2
    jmp glue 

irq_entry_73:
    push rdi
    push rdi
    push rsi
    mov rdi, 73
    mov rsi, cr2
    jmp glue 

irq_entry_74:
    push rdi
    push rdi
    push rsi
    mov rdi, 74
    mov rsi, cr2
    jmp glue 

irq_entry_75:
    push rdi
    push rdi
    push rsi
    mov rdi, 75
    mov rsi, cr2
    jmp glue 

irq_entry_76:
    push rdi
    push rdi
    push rsi
    mov rdi, 76
    mov rsi, cr2
    jmp glue 

irq_entry_77:
    push rdi
    push rdi
    push rsi
    mov rdi, 77
    mov rsi, cr2
    jmp glue 

irq_entry_78:
    push rdi
    push rdi
    push rsi
    mov rdi, 78
    mov rsi, cr2
    jmp glue 

irq_entry_79:
    push rdi
    push rdi
    push rsi
    mov rdi, 79
    mov rsi, cr2
    jmp glue 

irq_entry_80:
    push rdi
    push rdi
    push rsi
    mov rdi, 80
    mov rsi, cr2
    jmp glue 

irq_entry_81:
    push rdi
    push rdi
    push rsi
    mov rdi, 81
    mov rsi, cr2
    jmp glue 

irq_entry_82:
    push rdi
    push rdi
    push rsi
    mov rdi, 82
    mov rsi, cr2
    jmp glue 

irq_entry_83:
    push rdi
    push rdi
    push rsi
    mov rdi, 83
    mov rsi, cr2
    jmp glue 

irq_entry_84:
    push rdi
    push rdi
    push rsi
    mov rdi, 84
    mov rsi, cr2
    jmp glue 

irq_entry_85:
    push rdi
    push rdi
    push rsi
    mov rdi, 85
    mov rsi, cr2
    jmp glue 

irq_entry_86:
    push rdi
    push rdi
    push rsi
    mov rdi, 86
    mov rsi, cr2
    jmp glue 

irq_entry_87:
    push rdi
    push rdi
    push rsi
    mov rdi, 87
    mov rsi, cr2
    jmp glue 

irq_entry_88:
    push rdi
    push rdi
    push rsi
    mov rdi, 88
    mov rsi, cr2
    jmp glue 

irq_entry_89:
    push rdi
    push rdi
    push rsi
    mov rdi, 89
    mov rsi, cr2
    jmp glue 

irq_entry_90:
    push rdi
    push rdi
    push rsi
    mov rdi, 90
    mov rsi, cr2
    jmp glue 

irq_entry_91:
    push rdi
    push rdi
    push rsi
    mov rdi, 91
    mov rsi, cr2
    jmp glue 

irq_entry_92:
    push rdi
    push rdi
    push rsi
    mov rdi, 92
    mov rsi, cr2
    jmp glue 

irq_entry_93:
    push rdi
    push rdi
    push rsi
    mov rdi, 93
    mov rsi, cr2
    jmp glue 

irq_entry_94:
    push rdi
    push rdi
    push rsi
    mov rdi, 94
    mov rsi, cr2
    jmp glue 

irq_entry_95:
    push rdi
    push rdi
    push rsi
    mov rdi, 95
    mov rsi, cr2
    jmp glue 

irq_entry_96:
    push rdi
    push rdi
    push rsi
    mov rdi, 96
    mov rsi, cr2
    jmp glue 

irq_entry_97:
    push rdi
    push rdi
    push rsi
    mov rdi, 97
    mov rsi, cr2
    jmp glue 

irq_entry_98:
    push rdi
    push rdi
    push rsi
    mov rdi, 98
    mov rsi, cr2
    jmp glue 

irq_entry_99:
    push rdi
    push rdi
    push rsi
    mov rdi, 99
    mov rsi, cr2
    jmp glue 

irq_entry_100:
    push rdi
    push rdi
    push rsi
    mov rdi, 100
    mov rsi, cr2
    jmp glue 

irq_entry_101:
    push rdi
    push rdi
    push rsi
    mov rdi, 101
    mov rsi, cr2
    jmp glue 

irq_entry_102:
    push rdi
    push rdi
    push rsi
    mov rdi, 102
    mov rsi, cr2
    jmp glue 

irq_entry_103:
    push rdi
    push rdi
    push rsi
    mov rdi, 103
    mov rsi, cr2
    jmp glue 

irq_entry_104:
    push rdi
    push rdi
    push rsi
    mov rdi, 104
    mov rsi, cr2
    jmp glue 

irq_entry_105:
    push rdi
    push rdi
    push rsi
    mov rdi, 105
    mov rsi, cr2
    jmp glue 

irq_entry_106:
    push rdi
    push rdi
    push rsi
    mov rdi, 106
    mov rsi, cr2
    jmp glue 

irq_entry_107:
    push rdi
    push rdi
    push rsi
    mov rdi, 107
    mov rsi, cr2
    jmp glue 

irq_entry_108:
    push rdi
    push rdi
    push rsi
    mov rdi, 108
    mov rsi, cr2
    jmp glue 

irq_entry_109:
    push rdi
    push rdi
    push rsi
    mov rdi, 109
    mov rsi, cr2
    jmp glue 

irq_entry_110:
    push rdi
    push rdi
    push rsi
    mov rdi, 110
    mov rsi, cr2
    jmp glue 

irq_entry_111:
    push rdi
    push rdi
    push rsi
    mov rdi, 111
    mov rsi, cr2
    jmp glue 

irq_entry_112:
    push rdi
    push rdi
    push rsi
    mov rdi, 112
    mov rsi, cr2
    jmp glue 

irq_entry_113:
    push rdi
    push rdi
    push rsi
    mov rdi, 113
    mov rsi, cr2
    jmp glue 

irq_entry_114:
    push rdi
    push rdi
    push rsi
    mov rdi, 114
    mov rsi, cr2
    jmp glue 

irq_entry_115:
    push rdi
    push rdi
    push rsi
    mov rdi, 115
    mov rsi, cr2
    jmp glue 

irq_entry_116:
    push rdi
    push rdi
    push rsi
    mov rdi, 116
    mov rsi, cr2
    jmp glue 

irq_entry_117:
    push rdi
    push rdi
    push rsi
    mov rdi, 117
    mov rsi, cr2
    jmp glue 

irq_entry_118:
    push rdi
    push rdi
    push rsi
    mov rdi, 118
    mov rsi, cr2
    jmp glue 

irq_entry_119:
    push rdi
    push rdi
    push rsi
    mov rdi, 119
    mov rsi, cr2
    jmp glue 

irq_entry_120:
    push rdi
    push rdi
    push rsi
    mov rdi, 120
    mov rsi, cr2
    jmp glue 

irq_entry_121:
    push rdi
    push rdi
    push rsi
    mov rdi, 121
    mov rsi, cr2
    jmp glue 

irq_entry_122:
    push rdi
    push rdi
    push rsi
    mov rdi, 122
    mov rsi, cr2
    jmp glue 

irq_entry_123:
    push rdi
    push rdi
    push rsi
    mov rdi, 123
    mov rsi, cr2
    jmp glue 

irq_entry_124:
    push rdi
    push rdi
    push rsi
    mov rdi, 124
    mov rsi, cr2
    jmp glue 

irq_entry_125:
    push rdi
    push rdi
    push rsi
    mov rdi, 125
    mov rsi, cr2
    jmp glue 

irq_entry_126:
    push rdi
    push rdi
    push rsi
    mov rdi, 126
    mov rsi, cr2
    jmp glue 

irq_entry_127:
    push rdi
    push rdi
    push rsi
    mov rdi, 127
    mov rsi, cr2
    jmp glue 

irq_entry_128:
    push rdi
    push rdi
    push rsi
    mov rdi, 128
    mov rsi, cr2
    jmp glue 

irq_entry_129:
    push rdi
    push rdi
    push rsi
    mov rdi, 129
    mov rsi, cr2
    jmp glue 

irq_entry_130:
    push rdi
    push rdi
    push rsi
    mov rdi, 130
    mov rsi, cr2
    jmp glue 

irq_entry_131:
    push rdi
    push rdi
    push rsi
    mov rdi, 131
    mov rsi, cr2
    jmp glue 

irq_entry_132:
    push rdi
    push rdi
    push rsi
    mov rdi, 132
    mov rsi, cr2
    jmp glue 

irq_entry_133:
    push rdi
    push rdi
    push rsi
    mov rdi, 133
    mov rsi, cr2
    jmp glue 

irq_entry_134:
    push rdi
    push rdi
    push rsi
    mov rdi, 134
    mov rsi, cr2
    jmp glue 

irq_entry_135:
    push rdi
    push rdi
    push rsi
    mov rdi, 135
    mov rsi, cr2
    jmp glue 

irq_entry_136:
    push rdi
    push rdi
    push rsi
    mov rdi, 136
    mov rsi, cr2
    jmp glue 

irq_entry_137:
    push rdi
    push rdi
    push rsi
    mov rdi, 137
    mov rsi, cr2
    jmp glue 

irq_entry_138:
    push rdi
    push rdi
    push rsi
    mov rdi, 138
    mov rsi, cr2
    jmp glue 

irq_entry_139:
    push rdi
    push rdi
    push rsi
    mov rdi, 139
    mov rsi, cr2
    jmp glue 

irq_entry_140:
    push rdi
    push rdi
    push rsi
    mov rdi, 140
    mov rsi, cr2
    jmp glue 

irq_entry_141:
    push rdi
    push rdi
    push rsi
    mov rdi, 141
    mov rsi, cr2
    jmp glue 

irq_entry_142:
    push rdi
    push rdi
    push rsi
    mov rdi, 142
    mov rsi, cr2
    jmp glue 

irq_entry_143:
    push rdi
    push rdi
    push rsi
    mov rdi, 143
    mov rsi, cr2
    jmp glue 

irq_entry_144:
    push rdi
    push rdi
    push rsi
    mov rdi, 144
    mov rsi, cr2
    jmp glue 

irq_entry_145:
    push rdi
    push rdi
    push rsi
    mov rdi, 145
    mov rsi, cr2
    jmp glue 

irq_entry_146:
    push rdi
    push rdi
    push rsi
    mov rdi, 146
    mov rsi, cr2
    jmp glue 

irq_entry_147:
    push rdi
    push rdi
    push rsi
    mov rdi, 147
    mov rsi, cr2
    jmp glue 

irq_entry_148:
    push rdi
    push rdi
    push rsi
    mov rdi, 148
    mov rsi, cr2
    jmp glue 

irq_entry_149:
    push rdi
    push rdi
    push rsi
    mov rdi, 149
    mov rsi, cr2
    jmp glue 

irq_entry_150:
    push rdi
    push rdi
    push rsi
    mov rdi, 150
    mov rsi, cr2
    jmp glue 

irq_entry_151:
    push rdi
    push rdi
    push rsi
    mov rdi, 151
    mov rsi, cr2
    jmp glue 

irq_entry_152:
    push rdi
    push rdi
    push rsi
    mov rdi, 152
    mov rsi, cr2
    jmp glue 

irq_entry_153:
    push rdi
    push rdi
    push rsi
    mov rdi, 153
    mov rsi, cr2
    jmp glue 

irq_entry_154:
    push rdi
    push rdi
    push rsi
    mov rdi, 154
    mov rsi, cr2
    jmp glue 

irq_entry_155:
    push rdi
    push rdi
    push rsi
    mov rdi, 155
    mov rsi, cr2
    jmp glue 

irq_entry_156:
    push rdi
    push rdi
    push rsi
    mov rdi, 156
    mov rsi, cr2
    jmp glue 

irq_entry_157:
    push rdi
    push rdi
    push rsi
    mov rdi, 157
    mov rsi, cr2
    jmp glue 

irq_entry_158:
    push rdi
    push rdi
    push rsi
    mov rdi, 158
    mov rsi, cr2
    jmp glue 

irq_entry_159:
    push rdi
    push rdi
    push rsi
    mov rdi, 159
    mov rsi, cr2
    jmp glue 

irq_entry_160:
    push rdi
    push rdi
    push rsi
    mov rdi, 160
    mov rsi, cr2
    jmp glue 

irq_entry_161:
    push rdi
    push rdi
    push rsi
    mov rdi, 161
    mov rsi, cr2
    jmp glue 

irq_entry_162:
    push rdi
    push rdi
    push rsi
    mov rdi, 162
    mov rsi, cr2
    jmp glue 

irq_entry_163:
    push rdi
    push rdi
    push rsi
    mov rdi, 163
    mov rsi, cr2
    jmp glue 

irq_entry_164:
    push rdi
    push rdi
    push rsi
    mov rdi, 164
    mov rsi, cr2
    jmp glue 

irq_entry_165:
    push rdi
    push rdi
    push rsi
    mov rdi, 165
    mov rsi, cr2
    jmp glue 

irq_entry_166:
    push rdi
    push rdi
    push rsi
    mov rdi, 166
    mov rsi, cr2
    jmp glue 

irq_entry_167:
    push rdi
    push rdi
    push rsi
    mov rdi, 167
    mov rsi, cr2
    jmp glue 

irq_entry_168:
    push rdi
    push rdi
    push rsi
    mov rdi, 168
    mov rsi, cr2
    jmp glue 

irq_entry_169:
    push rdi
    push rdi
    push rsi
    mov rdi, 169
    mov rsi, cr2
    jmp glue 

irq_entry_170:
    push rdi
    push rdi
    push rsi
    mov rdi, 170
    mov rsi, cr2
    jmp glue 

irq_entry_171:
    push rdi
    push rdi
    push rsi
    mov rdi, 171
    mov rsi, cr2
    jmp glue 

irq_entry_172:
    push rdi
    push rdi
    push rsi
    mov rdi, 172
    mov rsi, cr2
    jmp glue 

irq_entry_173:
    push rdi
    push rdi
    push rsi
    mov rdi, 173
    mov rsi, cr2
    jmp glue 

irq_entry_174:
    push rdi
    push rdi
    push rsi
    mov rdi, 174
    mov rsi, cr2
    jmp glue 

irq_entry_175:
    push rdi
    push rdi
    push rsi
    mov rdi, 175
    mov rsi, cr2
    jmp glue 

irq_entry_176:
    push rdi
    push rdi
    push rsi
    mov rdi, 176
    mov rsi, cr2
    jmp glue 

irq_entry_177:
    push rdi
    push rdi
    push rsi
    mov rdi, 177
    mov rsi, cr2
    jmp glue 

irq_entry_178:
    push rdi
    push rdi
    push rsi
    mov rdi, 178
    mov rsi, cr2
    jmp glue 

irq_entry_179:
    push rdi
    push rdi
    push rsi
    mov rdi, 179
    mov rsi, cr2
    jmp glue 

irq_entry_180:
    push rdi
    push rdi
    push rsi
    mov rdi, 180
    mov rsi, cr2
    jmp glue 

irq_entry_181:
    push rdi
    push rdi
    push rsi
    mov rdi, 181
    mov rsi, cr2
    jmp glue 

irq_entry_182:
    push rdi
    push rdi
    push rsi
    mov rdi, 182
    mov rsi, cr2
    jmp glue 

irq_entry_183:
    push rdi
    push rdi
    push rsi
    mov rdi, 183
    mov rsi, cr2
    jmp glue 

irq_entry_184:
    push rdi
    push rdi
    push rsi
    mov rdi, 184
    mov rsi, cr2
    jmp glue 

irq_entry_185:
    push rdi
    push rdi
    push rsi
    mov rdi, 185
    mov rsi, cr2
    jmp glue 

irq_entry_186:
    push rdi
    push rdi
    push rsi
    mov rdi, 186
    mov rsi, cr2
    jmp glue 

irq_entry_187:
    push rdi
    push rdi
    push rsi
    mov rdi, 187
    mov rsi, cr2
    jmp glue 

irq_entry_188:
    push rdi
    push rdi
    push rsi
    mov rdi, 188
    mov rsi, cr2
    jmp glue 

irq_entry_189:
    push rdi
    push rdi
    push rsi
    mov rdi, 189
    mov rsi, cr2
    jmp glue 

irq_entry_190:
    push rdi
    push rdi
    push rsi
    mov rdi, 190
    mov rsi, cr2
    jmp glue 

irq_entry_191:
    push rdi
    push rdi
    push rsi
    mov rdi, 191
    mov rsi, cr2
    jmp glue 

irq_entry_192:
    push rdi
    push rdi
    push rsi
    mov rdi, 192
    mov rsi, cr2
    jmp glue 

irq_entry_193:
    push rdi
    push rdi
    push rsi
    mov rdi, 193
    mov rsi, cr2
    jmp glue 

irq_entry_194:
    push rdi
    push rdi
    push rsi
    mov rdi, 194
    mov rsi, cr2
    jmp glue 

irq_entry_195:
    push rdi
    push rdi
    push rsi
    mov rdi, 195
    mov rsi, cr2
    jmp glue 

irq_entry_196:
    push rdi
    push rdi
    push rsi
    mov rdi, 196
    mov rsi, cr2
    jmp glue 

irq_entry_197:
    push rdi
    push rdi
    push rsi
    mov rdi, 197
    mov rsi, cr2
    jmp glue 

irq_entry_198:
    push rdi
    push rdi
    push rsi
    mov rdi, 198
    mov rsi, cr2
    jmp glue 

irq_entry_199:
    push rdi
    push rdi
    push rsi
    mov rdi, 199
    mov rsi, cr2
    jmp glue 

irq_entry_200:
    push rdi
    push rdi
    push rsi
    mov rdi, 200
    mov rsi, cr2
    jmp glue 

irq_entry_201:
    push rdi
    push rdi
    push rsi
    mov rdi, 201
    mov rsi, cr2
    jmp glue 

irq_entry_202:
    push rdi
    push rdi
    push rsi
    mov rdi, 202
    mov rsi, cr2
    jmp glue 

irq_entry_203:
    push rdi
    push rdi
    push rsi
    mov rdi, 203
    mov rsi, cr2
    jmp glue 

irq_entry_204:
    push rdi
    push rdi
    push rsi
    mov rdi, 204
    mov rsi, cr2
    jmp glue 

irq_entry_205:
    push rdi
    push rdi
    push rsi
    mov rdi, 205
    mov rsi, cr2
    jmp glue 

irq_entry_206:
    push rdi
    push rdi
    push rsi
    mov rdi, 206
    mov rsi, cr2
    jmp glue 

irq_entry_207:
    push rdi
    push rdi
    push rsi
    mov rdi, 207
    mov rsi, cr2
    jmp glue 

irq_entry_208:
    push rdi
    push rdi
    push rsi
    mov rdi, 208
    mov rsi, cr2
    jmp glue 

irq_entry_209:
    push rdi
    push rdi
    push rsi
    mov rdi, 209
    mov rsi, cr2
    jmp glue 

irq_entry_210:
    push rdi
    push rdi
    push rsi
    mov rdi, 210
    mov rsi, cr2
    jmp glue 

irq_entry_211:
    push rdi
    push rdi
    push rsi
    mov rdi, 211
    mov rsi, cr2
    jmp glue 

irq_entry_212:
    push rdi
    push rdi
    push rsi
    mov rdi, 212
    mov rsi, cr2
    jmp glue 

irq_entry_213:
    push rdi
    push rdi
    push rsi
    mov rdi, 213
    mov rsi, cr2
    jmp glue 

irq_entry_214:
    push rdi
    push rdi
    push rsi
    mov rdi, 214
    mov rsi, cr2
    jmp glue 

irq_entry_215:
    push rdi
    push rdi
    push rsi
    mov rdi, 215
    mov rsi, cr2
    jmp glue 

irq_entry_216:
    push rdi
    push rdi
    push rsi
    mov rdi, 216
    mov rsi, cr2
    jmp glue 

irq_entry_217:
    push rdi
    push rdi
    push rsi
    mov rdi, 217
    mov rsi, cr2
    jmp glue 

irq_entry_218:
    push rdi
    push rdi
    push rsi
    mov rdi, 218
    mov rsi, cr2
    jmp glue 

irq_entry_219:
    push rdi
    push rdi
    push rsi
    mov rdi, 219
    mov rsi, cr2
    jmp glue 

irq_entry_220:
    push rdi
    push rdi
    push rsi
    mov rdi, 220
    mov rsi, cr2
    jmp glue 

irq_entry_221:
    push rdi
    push rdi
    push rsi
    mov rdi, 221
    mov rsi, cr2
    jmp glue 

irq_entry_222:
    push rdi
    push rdi
    push rsi
    mov rdi, 222
    mov rsi, cr2
    jmp glue 

irq_entry_223:
    push rdi
    push rdi
    push rsi
    mov rdi, 223
    mov rsi, cr2
    jmp glue 

irq_entry_224:
    push rdi
    push rdi
    push rsi
    mov rdi, 224
    mov rsi, cr2
    jmp glue 

irq_entry_225:
    push rdi
    push rdi
    push rsi
    mov rdi, 225
    mov rsi, cr2
    jmp glue 

irq_entry_226:
    push rdi
    push rdi
    push rsi
    mov rdi, 226
    mov rsi, cr2
    jmp glue 

irq_entry_227:
    push rdi
    push rdi
    push rsi
    mov rdi, 227
    mov rsi, cr2
    jmp glue 

irq_entry_228:
    push rdi
    push rdi
    push rsi
    mov rdi, 228
    mov rsi, cr2
    jmp glue 

irq_entry_229:
    push rdi
    push rdi
    push rsi
    mov rdi, 229
    mov rsi, cr2
    jmp glue 

irq_entry_230:
    push rdi
    push rdi
    push rsi
    mov rdi, 230
    mov rsi, cr2
    jmp glue 

irq_entry_231:
    push rdi
    push rdi
    push rsi
    mov rdi, 231
    mov rsi, cr2
    jmp glue 

irq_entry_232:
    push rdi
    push rdi
    push rsi
    mov rdi, 232
    mov rsi, cr2
    jmp glue 

irq_entry_233:
    push rdi
    push rdi
    push rsi
    mov rdi, 233
    mov rsi, cr2
    jmp glue 

irq_entry_234:
    push rdi
    push rdi
    push rsi
    mov rdi, 234
    mov rsi, cr2
    jmp glue 

irq_entry_235:
    push rdi
    push rdi
    push rsi
    mov rdi, 235
    mov rsi, cr2
    jmp glue 

irq_entry_236:
    push rdi
    push rdi
    push rsi
    mov rdi, 236
    mov rsi, cr2
    jmp glue 

irq_entry_237:
    push rdi
    push rdi
    push rsi
    mov rdi, 237
    mov rsi, cr2
    jmp glue 

irq_entry_238:
    push rdi
    push rdi
    push rsi
    mov rdi, 238
    mov rsi, cr2
    jmp glue 

irq_entry_239:
    push rdi
    push rdi
    push rsi
    mov rdi, 239
    mov rsi, cr2
    jmp glue 

irq_entry_240:
    push rdi
    push rdi
    push rsi
    mov rdi, 240
    mov rsi, cr2
    jmp glue 

irq_entry_241:
    push rdi
    push rdi
    push rsi
    mov rdi, 241
    mov rsi, cr2
    jmp glue 

irq_entry_242:
    push rdi
    push rdi
    push rsi
    mov rdi, 242
    mov rsi, cr2
    jmp glue 

irq_entry_243:
    push rdi
    push rdi
    push rsi
    mov rdi, 243
    mov rsi, cr2
    jmp glue 

irq_entry_244:
    push rdi
    push rdi
    push rsi
    mov rdi, 244
    mov rsi, cr2
    jmp glue 

irq_entry_245:
    push rdi
    push rdi
    push rsi
    mov rdi, 245
    mov rsi, cr2
    jmp glue 

irq_entry_246:
    push rdi
    push rdi
    push rsi
    mov rdi, 246
    mov rsi, cr2
    jmp glue 

irq_entry_247:
    push rdi
    push rdi
    push rsi
    mov rdi, 247
    mov rsi, cr2
    jmp glue 

irq_entry_248:
    push rdi
    push rdi
    push rsi
    mov rdi, 248
    mov rsi, cr2
    jmp glue 

irq_entry_249:
    push rdi
    push rdi
    push rsi
    mov rdi, 249
    mov rsi, cr2
    jmp glue 

irq_entry_250:
    push rdi
    push rdi
    push rsi
    mov rdi, 250
    mov rsi, cr2
    jmp glue 

irq_entry_251:
    push rdi
    push rdi
    push rsi
    mov rdi, 251
    mov rsi, cr2
    jmp glue 

irq_entry_252:
    push rdi
    push rdi
    push rsi
    mov rdi, 252
    mov rsi, cr2
    jmp glue 

irq_entry_253:
    push rdi
    push rdi
    push rsi
    mov rdi, 253
    mov rsi, cr2
    jmp glue 

irq_entry_254:
    push rdi
    push rdi
    push rsi
    mov rdi, 254
    mov rsi, cr2
    jmp glue 

irq_entry_255:
    push rdi
    push rdi
    push rsi
    mov rdi, 255
    mov rsi, cr2
    jmp glue 
