import { createRequire } from "node:module";
import path from "node:path";
const require = createRequire(import.meta.dirname);
export const GLUT = require(
	path.join(
		import.meta.dirname,
		"..",
		"bin",
		process.platform,
		process.arch,
		"native-glut.node",
	),
);
GLUT.mainLoop = async function () {
	GLUT.mainLoopBegin();
	await new Promise((resolve) => {
		const mainLoop = () => {
			if (GLUT.execState() === GLUT.EXEC_STATE_STOP) {
				resolve();
			} else {
				GLUT.mainLoopStep();
				//process.nextTick(mainLoop);
				setImmediate(mainLoop);
			}
		};
		//process.nextTick(mainLoop);
		setImmediate(mainLoop);
	});
	GLUT.mainLoopEnd();
};
GLUT.timerFunc = function (time, cb, value) {
	setTimeout(cb, time, value);
};
export default GLUT;
//# sourceMappingURL=index.js.map
