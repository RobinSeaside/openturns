#!/bin/sh
# upload doc to openturns.github.io

set -e

test "${CIRCLE_PROJECT_USERNAME}" = "openturns" || exit 0

git clone https://${GH_TOKEN}@github.com/openturns/openturns.github.io.git
if test -n "${CIRCLE_TAG}"
then
  CIRCLE_BRANCH="${CIRCLE_TAG:1}"
fi
mkdir -p openturns.github.io/${CIRCLE_PROJECT_REPONAME}/${CIRCLE_BRANCH}
cp -r  ~/.local/share/${CIRCLE_PROJECT_REPONAME}/doc/html/* openturns.github.io/${CIRCLE_PROJECT_REPONAME}/${CIRCLE_BRANCH}
cd openturns.github.io
touch .nojekyll
git config user.email "sayhi@circleci.com"
git config user.name "CircleCI"
git add -A .
git commit -a -m "CircleCI build ${CIRCLE_PROJECT_REPONAME} ${CIRCLE_BUILD_NUM}"
git push --quiet origin master > /dev/null 2>&1
