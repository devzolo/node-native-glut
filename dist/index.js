"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.GLUT = void 0;
const path_1 = __importDefault(require("path"));
exports.GLUT = require(path_1.default.join(__dirname, '..', 'bin', process.platform, process.arch, 'native-glut.node'));
exports.GLUT.mainLoop = function () {
    return __awaiter(this, void 0, void 0, function* () {
        exports.GLUT.mainLoopBegin();
        yield new Promise(resolve => {
            const mainLoop = () => {
                if (exports.GLUT.execState() === exports.GLUT.EXEC_STATE_STOP) {
                    resolve();
                }
                else {
                    exports.GLUT.mainLoopStep();
                    //process.nextTick(mainLoop);
                    setImmediate(mainLoop);
                }
            };
            //process.nextTick(mainLoop);
            setImmediate(mainLoop);
        });
        exports.GLUT.mainLoopEnd();
    });
};
exports.GLUT.timerFunc = function (time, cb, value) {
    setTimeout(cb, time, value);
};
exports.default = exports.GLUT;
//# sourceMappingURL=index.js.map