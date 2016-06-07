var gulp = require('gulp');
var pexec = require('child-process-promise').exec;
var watch = require('gulp-watch');
var fs = require('fs');
var md5 = require('md5');
var cwd = process.cwd();

var paths = {
    src: `${cwd}/src/`,
    tmp: `${cwd}/tmp/`,
    dest: `${cwd}/bin/`
};

var filemd5s = [];
gulp.task('build', function () {
    fs.readdir(paths.src, function (err, items) {
        console.log(items);
        items.forEach(function (item) {
            if (!item.includes('~')) {
                fs.readFile(`${paths.src}${item}`, function (err, buf) {
                    if (err) {
                        console.log(err);
                    } else {
                        var newmd5 = md5(buf);
                        if (filemd5s[item] == undefined || filemd5s[item] != newmd5) {
                            filemd5s[item] = newmd5;
                            var cppBuild = `clang++ ${paths.src}${item.split('.')[0]}.cpp -o ${paths.dest}${item.split('.cpp')[0]}`;
                            pexec(cppBuild)
                                .then(r => r.stdout)
                                .then(() => {
                                    var bashRun = `cd ${paths.dest} && ./${item.split('.cpp')[0]}`;
                                    console.log(`[${item}]`.toUpperCase());
                                    pexec(bashRun)
                                        .then(r => r.stdout)
                                        .then(console.log)
                                        .then(() => {
                                            console.log('-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+');
                                        })
                                        .catch(console.error);
                                })
                                .then(console.log)
                                .catch(console.error);
                        } else {
                            console.log(`[${item}]`.toUpperCase());
                            console.log('No change, no build!');
                        }
                    }
                })

            }
        });
    });
});

gulp.task('watch', function () {
    gulp.watch(`${paths.src}*.*`, ['build']);
});

gulp.task('default', ['watch'], function () {});
